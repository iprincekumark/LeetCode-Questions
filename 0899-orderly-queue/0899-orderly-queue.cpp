class Solution {
 public:
  string orderlyQueue(string &s, const int k) {
    if (k > 1) {
      sort(s.begin(), s.end());
      return s;
    }

    const int n = static_cast<int>(s.size());
    char min_letter = numeric_limits<char>::max();
    vector<int> min_letter_indices;
    for (int i = 0; i < n; ++i) {
      if (s[i] < min_letter) {
        min_letter = s[i];
        min_letter_indices.clear();
      }
      if (s[i] <= min_letter) {
        min_letter_indices.emplace_back(i);
      }
    }

    string ret;
    for (const int separator_index : min_letter_indices) {
      const string candidate = s.substr(separator_index) + s.substr(0, separator_index);
      if (ret.empty() || candidate < ret) {
        ret = move(candidate);
      }
    }
    return ret;
  }
};