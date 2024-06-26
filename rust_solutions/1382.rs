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
    pub fn balance_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut vals = Vec::new();
        Self::inorder(&root, &mut vals);
        Self::split(&vals, 0, vals.len())
    }

    fn inorder(node: &Option<Rc<RefCell<TreeNode>>>, vals: &mut Vec<i32>) {
        if let Some(node) = node {
            let node = node.borrow();
            Self::inorder(&node.left, vals);
            vals.push(node.val);
            Self::inorder(&node.right, vals);
        }
    }
    fn split(vals: &Vec<i32>, i: usize, j: usize) -> Option<Rc<RefCell<TreeNode>>> {
        if i == j {
            return None;
        }
        let m = (i + j) / 2;
        Some(Rc::new(RefCell::new(TreeNode {
            val: vals[m],
            left: Self::split(vals, i, m),
            right: Self::split(vals, m + 1, j),
        })))
    }
}
