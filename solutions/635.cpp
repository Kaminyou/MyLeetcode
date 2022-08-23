class LogSystem {
public:
    map<long long, int> time2id;
    LogSystem() {
        
    }
    long long timestamp2num(string& timestamp, string& granularity, bool isBegin) {
        long long year = stoll(timestamp.substr(0, 4));
        long long month = stoll(timestamp.substr(5, 2));
        long long day = stoll(timestamp.substr(8, 2));
        long long hour = stoll(timestamp.substr(11, 2));
        long long minute = stoll(timestamp.substr(14, 2));
        long long second = stoll(timestamp.substr(17, 2));
        long long res = 0;
        res += year;
        if (granularity == "Year") {
            if (isBegin) {
                month = 1;
                day = 1;
                hour = 0;
                minute = 0;
                second = 0;
            }
            else {
                month = 12;
                day = 31;
                hour = 24;
                minute = 60;
                second = 60;
            }
        }
        res = res * 12 + month;
        if (granularity == "Month") {
            if (isBegin) {
                day = 1;
                hour = 0;
                minute = 0;
                second = 0;
            }
            else {
                day = 31;
                hour = 24;
                minute = 60;
                second = 60;
            }
        }
        res = res * 31 + day;
        if (granularity == "Day") {
            if (isBegin) {
                hour = 0;
                minute = 0;
                second = 0;
            }
            else {
                hour = 24;
                minute = 60;
                second = 60;
            }
        }
        res = res * 24 + hour;
        if (granularity == "Hour") {
            if (isBegin) {
                minute = 0;
                second = 0;
            }
            else {
                minute = 60;
                second = 60;
            }
        }
        res = res * 60 + minute;
        if (granularity == "Minute") {
            if (isBegin) {
                second = 0;
            }
            else {
                second = 60;
            }
        }
        res = res * 60 + second;
        return res;
    }
    void put(int id, string timestamp) {
        string granularity = "Second";
        long long time = timestamp2num(timestamp, granularity, false);
        time2id[time] = id;
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        long long startTime = timestamp2num(start, granularity, true);
        long long endTime = timestamp2num(end, granularity, false);
        // >= start
        auto it = time2id.lower_bound(startTime);
        vector<int> res;
        while (it != time2id.end() && it->first <= endTime) {
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */