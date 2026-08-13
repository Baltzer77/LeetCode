pub struct Solution {}

use std::cmp::max;

#[derive(Clone,Copy)]
struct Node {
    pub left_char : u8,
    pub right_char : u8,
    pub left_end_index : i32, // starts from the left and moves right
    pub right_end_index : i32, // starts from the right and moves left
    pub longest : i32,
}

impl Solution {

    pub fn longest_repeating(s: String, query_charaters: String, query_indices: Vec<i32>) -> Vec<i32> {
        let n = s.len();
        let k = query_charaters.len();

        let s_bytes = s.as_bytes();
        let query_bytes = query_charaters.as_bytes();

        let mut nodes = Self::build_tree(&s_bytes);
        let mut res = vec![0; k];

        for i in 0..k {
            Self::query(&mut nodes, query_indices[i] as usize, query_bytes[i], 0, 0, (n-1) as i32);
            res[i] = nodes[0].longest as i32;
        }

        res
    }

    fn build_tree(s: &[u8]) -> Vec<Node> {
        let n = s.len();
        let default_node = Node{
            left_char: 0,
            right_char: 0,
            left_end_index: 0,
            right_end_index: 0,
            longest: 0,
        };

        let mut nodes = vec![default_node; n * 4];
        Self::build_tree_helper(&s, &mut nodes, 0, 0, (n - 1) as i32);

        nodes
    }

    fn build_tree_helper(s: &[u8], nodes: &mut [Node], i: usize, l: i32, r: i32) {
        if l == r {
            let node = Node {
                left_char: s[l as usize],
                right_char: s[l as usize],
                left_end_index: r,
                right_end_index: r,
                longest: 1,
            };
            nodes[i] = node;

            return;
        }

        let mid = l + ((r - l) >> 1);

        Self::build_tree_helper(&s, nodes, i * 2 + 1, l, mid);
        Self::build_tree_helper(&s, nodes, i * 2 + 2, mid + 1, r);

        let left_node : &Node = &nodes[i * 2 + 1];
        let right_node : &Node = &nodes[i * 2 + 2];

        nodes[i] = Self::merge_nodes(&left_node, &right_node, l, r);
    }

    fn merge_nodes(left_node: &Node, right_node: &Node, l: i32, r: i32) -> Node {
        // check if we cross center and reach either end
        // [aaa] [abb]
        // [bba] [aaa]
        // [aba] [aba]
        let mid = l + ((r - l) >> 1);

        // entire range is covered 
        if left_node.left_char == right_node.left_char && left_node.left_end_index == mid && right_node.right_end_index == mid + 1 {
            let node = Node {
                left_char: left_node.left_char,
                right_char: left_node.right_char,
                left_end_index: r,
                right_end_index: l,
                longest: r - l + 1,
            };
            return node;
        }

        // crosses and reaches all the way to the right
        if left_node.right_char == right_node.left_char && right_node.left_end_index == r {
            let crossing = r - left_node.right_end_index + 1;
            let node = Node {
                left_char: left_node.left_char,
                right_char: left_node.right_char,
                left_end_index: left_node.left_end_index,
                right_end_index: left_node.right_end_index,
                longest: max(crossing, left_node.longest),
            };
            return node;
        }

        // crosses and reaches all the way to the left
        if left_node.left_char == right_node.left_char && left_node.right_end_index == l {
            let crossing = right_node.left_end_index - l + 1;
            let node = Node {
                left_char: left_node.left_char,
                right_char: right_node.right_char,
                left_end_index: right_node.left_end_index,
                right_end_index: right_node.right_end_index,
                longest: max(crossing, right_node.longest),
            };
            return node;
        }

        // otherwise check for cross and see if longer than best 
        let mut longest = max(left_node.longest, right_node.longest); 
        if left_node.right_char == right_node.left_char {
            longest = max(longest, right_node.left_end_index - left_node.right_end_index + 1);
        } 

        let node = Node {
            left_char: left_node.left_char,
            right_char: right_node.right_char,
            left_end_index: left_node.left_end_index,
            right_end_index: right_node.right_end_index,
            longest: longest,
        };
        return node;
    }

    fn query(mut nodes: &mut [Node], query_index: usize,  c: u8, i: usize, l: i32, r: i32) {
        if l == r {
            nodes[i] = Node {
                left_char: c,
                right_char: c,
                left_end_index: l,
                right_end_index: l,
                longest: 1,
            };
            return;
        }

        let mid = l + ((r - l) >> 1);

        if query_index <= mid as usize {
            Self::query(&mut nodes, query_index, c, i *2 + 1, l, mid);
        } else {
            Self::query(&mut nodes, query_index, c, i *2 + 2, mid + 1, r);
        }

        let left_node: &Node = &nodes[i * 2 + 1];
        let right_node: &Node = &nodes[i * 2 + 2];

        nodes[i] = Self::merge_nodes(&left_node, &right_node, l, r);
    }

}