#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity;
    int minFreq;

    unordered_map<int, pair<int, int>> data;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> position;

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        if (!data.count(key))
            return -1;

        int value = data[key].first;
        int freq = data[key].second;

        freqList[freq].erase(position[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        freq++;

        freqList[freq].push_front(key);
        position[key] = freqList[freq].begin();
        data[key].second = freq;

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (data.count(key)) {
            data[key].first = value;
            get(key);
            return;
        }

        if (data.size() == capacity) {
           
