/*
 * Complete the function signature.
 */
void Contest::swap(Contest& other)
{
Contest temp = other;

other.scores = scores;

scores = temp.scores;

}

void swap_scores(std::vector<int> first, std::vector<int> second) {
    /*
     * 1. Instantiate the object first_contest with the scores provided by the array first.
     */
    
    Contest first_contest = Contest(first);



    /*
     * 2. Instantiate the object second_contest with the scores provided by the array second.
     */
    Contest second_contest = Contest(second);
    
    /*
     * 3. Swap the scores of the both the contest objects.
     */
    first_contest.swap(second_contest);
