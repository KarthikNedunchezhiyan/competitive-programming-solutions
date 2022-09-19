enum ParserState {
    PATH,
    FILE_NO,
    TEXT
};

class Parser {
public:
    // <text, <path, file_nos>>
    unordered_map<string_view, vector<pair<string_view, string_view>>> cache;
    ParserState current_state;

    void parse(string &target) {
        current_state = ParserState::PATH;
        int cursor_start = 0, i = 0;
        string_view path, sv_target = string_view(target), file_no;

        while (i < target.length()) {
            switch (current_state) {
                case ParserState::PATH: {
                    if (target[i] == ' ') {
                        path = sv_target.substr(cursor_start, i - cursor_start);
                        cursor_start = ++i;
                        current_state = ParserState::FILE_NO;
                    }
                }
                case ParserState::FILE_NO: {
                    if (target[i] == '.') {
                        file_no = sv_target.substr(cursor_start, i - cursor_start);
                        cursor_start = i += 4;
                        current_state = ParserState::TEXT;
                    }
                }
                case ParserState::TEXT: {
                    if (target[i] == ')') {
                        string_view text = sv_target.substr(cursor_start, i - cursor_start);
                        if (!cache.count(text)) cache[text] = {};
                        cache[text].emplace_back(path, file_no);
                        cursor_start = i += 2;
                        current_state = ParserState::FILE_NO;
                        continue;
                    }
                }
            }
            i++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        Parser *parser = new Parser();
        for (string &path: paths) parser->parse(path);
        vector<vector<string>> result;

        for (auto &entry: parser->cache) {
            if (entry.second.size() > 1) {
                result.emplace_back();
                for (auto &duplicate: entry.second)
                    result.back().emplace_back(string(duplicate.first) + "/" + string(duplicate.second) + ".txt");
            }
        }
        return result;
    }
};
