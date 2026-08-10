pub struct Solution {}

use std::collections::BinaryHeap;
use std::cmp::Ordering;

struct Stone {
    pub alice: i32,
    pub bob: i32
}

impl Ord for Stone {
    fn cmp(&self, other: &Self) -> Ordering {
        let ab_self = self.alice + self.bob;
        let ab_other = &other.alice + &other.bob;

        if ab_self < ab_other {
            Ordering::Less
        } else if ab_self > ab_other {
            Ordering::Greater
        } else {
            Ordering::Equal
        }
    }
}

impl PartialOrd for Stone {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Stone {
    fn eq(&self, other: &Self) -> bool {
        self.alice == other.alice && self.bob == other.bob
    }
}

impl Eq for Stone {}

impl Solution {
    pub fn stone_game_vi(alice_values: Vec<i32>, bob_values: Vec<i32>) -> i32 {
        let n = alice_values.len();


        let mut heap:BinaryHeap<Stone> = alice_values.into_iter()
                                          .zip(bob_values)
                                          .map(|(alice,bob)| Stone {alice,bob})
                                          .collect();

        let mut alice = 0;
        let mut bob = 0;
        let mut turn = true;
        while !heap.is_empty() {
            if turn {
                alice += heap.pop().unwrap().alice; 
            } else {
                bob += heap.pop().unwrap().bob;
            }

            turn = !turn;
        }

        if alice > bob {
            1
        } else if bob > alice {
            -1
        } else {
            0
        }
    }
}