#[repr(transparent)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct Handle(usize);
const NIL_HANDLE: Handle = Handle(usize::MAX);
struct TrieNode {
    is_end: bool,
    children: [Handle; 26],
}
struct Trie {
    nodes: Vec<TrieNode>,
    root: Handle,
}
impl Trie {
    fn new() -> Self {
        let mut trie = Trie { nodes: Vec::new(), root: NIL_HANDLE};
        trie.root = trie.new_node();
        trie
    }
    fn add_word(&mut self, s: &[u8]) {
        let mut hcurr = self.root;
        for &ch in s {
            let idx = (ch - b'a') as usize;
            let mut hnext = self.nodes[hcurr.0].children[idx];
            if hnext == NIL_HANDLE {
                hnext = self.new_node();
                self.nodes[hcurr.0].children[idx] = hnext;
            }
            hcurr = hnext;
        }
        self.nodes[hcurr.0].is_end = true;
    }
    fn find_prefixes(&self, s: &[u8]) -> Option<Vec<usize>> {
        let mut result = None;
        let mut hcurr = self.root;
        for (i, &ch) in s.iter().enumerate() {
            let idx = (ch - b'a') as usize;
            let hnext = self.nodes[hcurr.0].children[idx];
            if hnext == NIL_HANDLE {break;}
            if self.nodes[hnext.0].is_end {
                result.get_or_insert_with(|| Vec::new()).push(i);
            }
            hcurr = hnext;
        }
        result
    }
    fn new_node(&mut self) -> Handle {
        let node = TrieNode {is_end: false, children: [NIL_HANDLE; 26]};
        self.nodes.push(node);
        Handle(self.nodes.len() - 1)
    }
}


impl Solution {
    pub fn replace_words(dictionary: Vec<String>, sentence: String) -> String {
        let mut trie = Trie::new();
        let mut answ = String::new();
        for word in dictionary {
            trie.add_word(word.as_bytes());
        }
        for word in sentence.split(' ') {
            if let Some(prefixes) = trie.find_prefixes(word.as_bytes()) {
                answ.push_str(&word[0..=prefixes[0]]);
            }
            else {
                answ.push_str(word);
            }
            answ.push(' ');
        }
        answ.pop();
        answ
    }
}
