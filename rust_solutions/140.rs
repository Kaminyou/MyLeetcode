use std::collections::HashSet;
impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> Vec<String> {
        let dict = word_dict.into_iter().collect::<HashSet<String>>();
        let mut ans = vec![];
        fn dfs(s: String, cur: &mut Vec<String>, dict: &HashSet<String>, ans: &mut Vec<String>) {
            if s.is_empty() {
                ans.push(cur.clone().join(" "));
                return;
            }
            for w in dict {
                if let Some(0) = s.find(w) {
                    cur.push(w.clone());
                    dfs(s[w.len()..].to_string(), cur, dict, ans);
                    cur.pop();
                }
            }
        }
        dfs(s, &mut vec![], &dict, &mut ans);
        ans
    }
}
