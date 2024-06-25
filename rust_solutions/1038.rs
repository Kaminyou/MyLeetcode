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
    pub fn bst_to_gst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        fn traverse(root: Option<Rc<RefCell<TreeNode>>>, sum: &mut i32) -> Option<Rc<RefCell<TreeNode>>> {
            let node = root?;
            let mut node_ref = node.borrow_mut();

            node_ref.right = traverse(node_ref.right.take(), sum);
            node_ref.val += *sum;
            *sum = node_ref.val;
            node_ref.left = traverse(node_ref.left.take(), sum);
            drop(node_ref);
            Some(node)
        }
        let mut sum = 0;
        traverse(root, &mut sum)
        
    }
}
