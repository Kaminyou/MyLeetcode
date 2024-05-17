// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn remove_leaf_nodes(root: Option<Rc<RefCell<TreeNode>>>, target: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node) = root.clone() {
            let mut borrowed = node.borrow_mut();
            borrowed.left = Self::remove_leaf_nodes(borrowed.left.take(), target);
            borrowed.right = Self::remove_leaf_nodes(borrowed.right.take(), target);
            if borrowed.left.is_none() && borrowed.right.is_none() && borrowed.val == target {
                return None
            }
        }
        root
    }
}
