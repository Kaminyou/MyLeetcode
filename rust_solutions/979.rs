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
    fn dfs(node: Option<Rc<RefCell<TreeNode>>>, sum: &mut i32) -> i32 {
        if let Some(node) = node {
            let mut temp_node = node.borrow_mut();
            let left = Self::dfs(temp_node.left.take(), sum);
            let right = Self::dfs(temp_node.right.take(), sum);
            *sum += left.abs() + right.abs();
            return left + right + temp_node.val - 1;
        }
        return 0;
    }
    pub fn distribute_coins(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut sum = 0;
        Self::dfs(root, &mut sum);
        return sum;
    }
}
