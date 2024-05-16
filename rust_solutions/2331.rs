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
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(node) = node {
            let node = node.borrow();
            if node.val == 0 {
                return false;
            }
            if node.val == 1 {
                return true;
            }
            let left = Self::dfs(&node.left);
            let right = Self::dfs(&node.right);
            if node.val == 2 {
                return left || right;
            }
            return left && right;
        }
        return true;
    }
    pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        return Self::dfs(&root);
    }
}
