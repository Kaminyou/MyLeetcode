impl Solution {
    pub fn num_rescue_boats(people: Vec<i32>, limit: i32) -> i32 {
        let mut people = people;
        people.sort_unstable();
        let mut left: i32 = 0;
        let mut right: i32 = (people.len() - 1) as i32;

        let mut count: i32 = 0;
        while (left <= right) {
            if (people[left as usize] + people[right as usize] > limit) {
                right -= 1;
            }
            else {
                left += 1;
                right -= 1;
            }
            count += 1;
        }
        return count;
    }
}
