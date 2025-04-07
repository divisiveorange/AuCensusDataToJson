//
// Created by Alexander Garrity on 27/2/2024.
//

#ifndef TRIEELEMENT_H
#define TRIEELEMENT_H
#include <map>
#include <sstream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>


class TrieElement {
public:
    TrieElement(std::string phrase, TrieElement* up)
    {
        this->phrase = std::move(phrase);
        head = false;
        this->up = up;
        nextMap = std::make_unique<std::map<std::string, TrieElement*>>();
    };
    TrieElement()
    {
        nextMap = std::make_unique<std::map<std::string, TrieElement*>>();
        head = true;
    }

    TrieElement* add(std::string phrase)
    {
        if (nextMap->contains(phrase))
        {
            return nextMap->at(phrase);
        }
        auto next = new TrieElement(phrase, this);
        nextMap->insert({phrase, next});
        return next;
    }
    ~TrieElement()
    {
        if (nextMap == nullptr)
        {
            return;
        }
        for (auto item : *nextMap)
        {
            delete item.second;
        }
    }
    std::string getPhrase() const
    {
        return phrase;
    }
    TrieElement* getNext(std::string phrase) const
    {
         return nextMap->at(phrase);
    }
    bool contains(std::string phrase) const
    {
        return nextMap->contains(phrase);
    }
    bool end() const
    {
        return fin;
    }
    bool top() const
    {
        return head;
    }
    TrieElement* getUp() const
    {
        return up;
    }
    void makeEnd()
    {
        fin = true;
    }
    std::vector<TrieElement*> getAllNext()
    {
        std::vector<TrieElement*> allNext;
        for (auto nextPair : *nextMap)
        {
            allNext.push_back(nextPair.second);
        }
        return allNext;
    }
    void merge(TrieElement* below)
    {
        up->nextMap->erase(phrase);
        std::string newPhrase = phrase + below->phrase;
        phrase = newPhrase;
        fin = below->fin;
        nextMap = std::move(below->nextMap);
        up->nextMap->insert({phrase, this});
        auto nexts = getAllNext();
        for (auto next : nexts)
        {
            next->up = this;
        }
        delete below;
    }
    void sameLevel(std::vector<TrieElement*> below)
    {

        if (up != nullptr)
        {
            for (auto next : below)
            {
                up->nextMap->insert({phrase + next->phrase, next});
            }
        }
        for (auto next : below)
        {
            next->phrase = phrase + next->phrase;
            next->up = up;
        }
        nextMap->clear();
    }
    static std::unique_ptr<std::vector<std::string>> breakUp(std::string str)
    {
        auto postSplit = std::make_unique<std::vector<std::string>>();
        postSplit->push_back("");
        for (auto letter : str)
        {
            if (letter == '_')
            {
                postSplit->push_back("_");
            }
            else
            {
                postSplit->back().push_back(letter);
            }
        }
        return postSplit;
    }

private:
    std::string phrase;
    bool head;
    TrieElement* up;
    std::unique_ptr<std::map<std::string, TrieElement*>> nextMap;
    bool fin;
};



#endif //TRIEELEMENT_H
