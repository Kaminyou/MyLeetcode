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
    pub fn double_it(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut st = None;

        while let Some(node) = &mut head {
            std::mem::swap(&mut st, &mut node.next);
            std::mem::swap(&mut st, &mut head);
        }

        let mut x = 0;
        
        while let Some(node) = &mut st {
            x += node.val * 2;
            node.val = x % 10;
            x /= 10;
            std::mem::swap(&mut head, &mut node.next);
            std::mem::swap(&mut head, &mut st);
        }

        if x > 0 {
            head = Some(Box::new(ListNode {val: x, next: head}));
        }

        head
    }
}
