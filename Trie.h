//
// Created by Alexander Garrity on 27/2/2024.
//

#ifndef TRIE_H
#define TRIE_H
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include "TrieElement.h"
#include "include/json.hpp"


class Trie {
public:
    Trie()
    {
        head = new TrieElement();
    }
    void add(std::string str)
    {
        auto curr = head;
        auto phrases = TrieElement::breakUp(std::move(str));
        for (const auto& phrase : *phrases)
        {
            curr = curr->add(phrase);
        }
        curr->makeEnd();
    }
    bool contains(std::string str) const
    // Broken
    {
        auto phrases = TrieElement::breakUp(str);
        auto curr = head;
        for (int i = 0; i < phrases->size(); i++)
        {
            while (!curr->contains(phrases->at(i)))
            {
                if (i+1 >= phrases->size()) return false;
                (*phrases)[i+1] = (*phrases)[i] + (*phrases)[i+1];
                i++;
            };
            auto next = curr->getNext(phrases->at(i));
            curr = next;
        }
        return true;
    }
    std::vector<std::string> getStrings()
    {
        auto array = std::array<int, 5>();
        auto strings = new std::vector<std::string>;
        findStringsBelow(head, strings);
        auto returnable = *strings;
        delete strings;
        return returnable;
    }
    TrieElement* getHead() const
    {
        return head;
    }
    void combine()
    {
        combineSingleNodes(head);
    }
    ~Trie()
    {
        delete head;
    };
    nlohmann::json* getJson()
    {
        auto jason = new nlohmann::json({});
        getJson(head, jason);
        return jason;
    }
    static void getJson(TrieElement* node, nlohmann::json* jason)
    {
        if (!node->top())
        {
            (*jason)[node->getPhrase()] = {};
            jason = &jason->at(node->getPhrase());
        }
        auto nexts = node->getAllNext();
        for (auto next : nexts)
        {
            getJson(next, jason);
        }
    }
    static void combineSingleNodes(TrieElement* node)
    {
        redoPoint:
        auto allNext = node->getAllNext();
        if (!node->end() && allNext.size() == 1)
        {
            node->merge(allNext.front());
            combineSingleNodes(node);
            return;
        }
        if (node->end() && !allNext.empty())
        {
            node->sameLevel(allNext);
        }
        switch (allNext.size())
        {
        case 0:
            return;
        default:
            for (auto next : allNext)
            {
                combineSingleNodes(next);
            }
        }
    }
    static void findStringsBelow(TrieElement* element, std::vector<std::string>* strings)
    {
        auto allNext = element->getAllNext();
        if (element->end())
        {
            strings->push_back(getAbove(element));
        }
        for (auto next : allNext)
        {
            findStringsBelow(next, strings);
        }
    }
    static std::string getAbove(TrieElement* tail)
    {
        auto curr = tail;
        std::vector<std::string> strs;
        while(curr->getUp() != nullptr)
        {
            strs.push_back(curr->getPhrase());
            curr = curr->getUp();
        }
        std::string str;
        for (int i = strs.size() - 1; i >= 0; i--)
        {
            str.append(strs.at(i));
        }
        return str;
    }
private:
    TrieElement* head;
};
std::map<std::string, nlohmann::json*> getMapToEnd(nlohmann::json* jason);



#endif //TRIE_H
