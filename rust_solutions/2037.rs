impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort_unstable();
        students.sort_unstable();
        seats.iter().zip(students.iter()).map(|(seat, student)| (seat - student).abs()).sum()
    }
}
