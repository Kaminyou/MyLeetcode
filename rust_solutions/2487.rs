// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut stack = Vec::new();
        let mut current_node = head;
        while let Some(node) = current_node {
            while !stack.is_empty() && stack[stack.len() - 1] < node.val {
                stack.pop();
            }
            stack.push(node.val);
            current_node = node.next;
        }
        let mut head = None;
        while let Some(val) = stack.pop() {
            head = Some(Box::new(ListNode {val: val, next: head}));
        }
        head
    }
}
