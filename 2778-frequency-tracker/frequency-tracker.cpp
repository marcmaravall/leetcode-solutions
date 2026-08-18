class FrequencyTracker {
private:
    std::unordered_map<int, int> m_freq;
    std::unordered_map<int, int> m_freqFreq;

public:
    FrequencyTracker() {}

    void add(int number) {
        int oldFreq = m_freq[number];
        int newFreq = oldFreq + 1;

        if (oldFreq > 0)
            m_freqFreq[oldFreq]--;

        m_freq[number] = newFreq;
        m_freqFreq[newFreq]++;
    }

    void deleteOne(int number) {
        if (m_freq[number] == 0)
            return;

        int oldFreq = m_freq[number];
        int newFreq = oldFreq - 1;

        m_freqFreq[oldFreq]--;

        if (newFreq > 0) {
            m_freqFreq[newFreq]++;
            m_freq[number] = newFreq;
        } else {
            m_freq.erase(number);
        }
    }

    bool hasFrequency(int frequency) {
        return m_freqFreq[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */