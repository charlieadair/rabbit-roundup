# rabbit-roundup
project2 for cs 4150 algorithms with dr. travis martin
A truck transporting the rabbits is diverted through the University of Utah just minutes before classes begin. Amid the chaos of students searching for parking, a collision tips the truck over and opens the rabbit enclosures. The rabbits promptly disperse across campus.

Domestic rabbits have a gestation period of approximately 30 days and can produce 1-14 offspring per litter, so this is a big problem that calls for a big solution: divide and conquer algorithms. University officials declare the escape a campus crisis because of the landscaping damage it will cause.

The university has identified an array of locations (1 through n) on campus where rabbits exist. For each location it has determined the dollars of landscaping damage that rabbits will cause.

Animal control has one crew available to send to campus, but the crew is not free. It charges a fixed fee for every location it visits. When it visits a location it removes all rabbits, protecting the location from any damage.

The crew also has very limited mobility. The university can choose the crew's start and end locations, but then the crew visits every location between them, removing rabbits and charging a fee for each location as it goes (it cannot skip over locations).

The University, which cares much more about money than rabbits, would like your help to maximize its savings! Its savings are the total landscaping damages prevented by the animal control crew minus the crew's fees.

Submit a program that outputs the maximum amount of money the University of Utah can save.

IMPORTANT: Your program must be a recursive divide-and-conquer algorithm and it should be O(n log n).

This problem requires a new divide-and-conquer algorithm (different from what we've learned in class). Apply the principles we've learned in class: can you solve this problem by dividing it into parts, delegating to recursion, and then combining the results?

This should be solvable, but challenging, with what you've learned so far. If you're feeling stuck on the divide and conquer idea, see the following hint.

 Small hint (spoiler alert! think on your own for at least 30 minutes first!)
Input
The first line contains two space-separated integers n and p:

1 ≤ n ≤ 100,000 is the number of locations on campus.
1 ≤ p ≤ 1,000 is the animal control crew’s fee per location.
The next line contains n space-separated integers a1, a2, …, an, where 0 ≤ ai ≤ 2,000.

The value ai is the amount of damages rabbits in location i would cause if not removed.

Note that the animal control crew's mobility restrictions mean that they can only visit adjacent locations in this array. E.g. it can visit locations 2, 3 or locations 5, 6, 7, but not locations 4, 6, 7 (it cannot skip over location 5).

Output
Output one integer: the maximum savings obtainable by hiring the crew (0 if the university cannot save money by hiring the animal control crew).

Sample Input 1	Sample Output 1
5 10
4 18 1 21 3
11
In the above example, the university saves the most money if it sends the crew to only location 4.

Sample Input 2	Sample Output 2
6 20
18 35 6 80 15 21
61
In the above example, the university saves the most money if it sends the crew to locations 2, 3, and 4.

Sample Input 3	Sample Output 3
3 10
2 8 5
0
Thanks to TA John Radford for his large contributions to this problem, especially on all rabbit-related matters.
