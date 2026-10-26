class RandomizedCollection {
private:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mpp;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool notPresent = (mpp.find(val) == mpp.end() || mpp[val].empty());
        arr.push_back(val);
        mpp[val].insert(arr.size() - 1);
        return notPresent;
    }

    bool remove(int val) {
        if (mpp.find(val) == mpp.end() || mpp[val].empty()) {
            return false;
        }

        int idxToRemove = *(mpp[val].begin());
        int lastVal = arr.back();

        mpp[val].erase(idxToRemove);

        if (idxToRemove != arr.size() - 1) {
            arr[idxToRemove] = lastVal;
            mpp[lastVal].erase(arr.size() - 1);
            mpp[lastVal].insert(idxToRemove);
        }

        if (mpp[val].empty()) {
            mpp.erase(val);
        }
        arr.pop_back();

        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};