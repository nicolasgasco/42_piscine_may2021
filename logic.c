/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:48:54 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/25 18:11:48 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
VALID NUMBERS
For the numbers to be valid, they must be bigger or equal than 1 and smaller or equal than the number of block on each side (e.g. 1, 2, 3, 4 in the example above).


SUMS OF OPPOSITE NUMBERS
The sum of two opposite numbers (e.g. 3 and 1 in the example above) cannot exceed 5 in a 4x4 grid.
 	- If the sum exceeds 5 --> ERROR 


SAFE CASES
1) All 1-4 and 4-1 pairs can be filled immediately with either 1, 2, 3, 4 or 4, 3, 2, 1.
2) Wherever there is a pair containg a 1 (e.g 1-3, 2-1), a 4 can be added immediately.
3) All 2-1 and 1-2 pairs start and end with either a 3 or a 4, e.g. 2 -> 3 * * 4 <- 1.
4) In all 3-2 and 2-3 pairs, the position of 4 is marked by the number themselves (e.g. 3 -> * * 4 * <- 2).

OTHER CHECK
Once the first 4 safe cases are checked, other two can be implemented:
1) Checking if by any chance there are rows or columns with only one field missing. This can be done at every "cycle" or whenever suitable. 
2) Checking if there are three 4s and the fourth one can be deducted (a first while loop to find the array (row) missing a 4 and two nested while loops to "scan" columns and find the index of the missing 4). 

CHOOSING A STRATEGY
At this point of the script, the board is relatively populated (see illustration below) and two different strategies can be chosen.

  | 3| 1| 2| 3|
--|--|--|--|--|--
 2|  | 4|  |  |3
--|--|--|--|--|--
 3|  | 3| 4|  |2 
--|--|--|--|--|--
 2|  | 2|  | 4|1
--|--|--|--|--|--
 1| 4| 1|  |  |2
--|--|--|--|--|--
  | 1| 4| 2| 2|

1) Prioritizing cases that are relatively easy. The most notable ones are rows or columns where only two adjacent fields are missing and the 4 is given. Following this route entails quite a lot of logic, but it essentially boils down to putting the remaining numbers either in ascending or descending order.

- Brute force approach. Whenever two (or even three numbers) are missing, all possible combinations can be double-checked against the existing numbers.
	- This approach struggles when the board is not very populated.
	- Both approaches can be used to prioritize particularly easy cases.
	- This approach can get quite complicated when more than one option is valid.

FILLING TWO ADJACENT EMPTY BOXES
When two adjacent boxes are empty and a 4 is available, the solution can be easy to find. Let's populate the board above with the rock-solid cases:

  | 3| 1| 2| 3|
--|--|--|--|--|--
 2|  | 4|  |  |3
--|--|--|--|--|--
 3|  | 3| 4|  |2 
--|--|--|--|--|--
 2|  | 2|  | 4|1
--|--|--|--|--|--
 1| 4| 1|  |  |2
--|--|--|--|--|--
  | 1| 4| 2| 2|

Once the board is populated this way, we can prioritize, say, the last 1-2 pair, i.d. 1 -> 4 1 * * <- 2.
The only two available numbers are 2 and 3. Since they next to the 2 and one of the visible blocks must be the 4, and since the 4 is in the 3rd position, the numbers must be put in descending order, i.e. 2, 3.

  | 3| 1| 2| 3|
--|--|--|--|--|--
 2|  | 4|  |  |3
--|--|--|--|--|--
 3|  | 3| 4|  |2 
--|--|--|--|--|--
 2|  | 2|  | 4|1
--|--|--|--|--|--
 1| 4| 1| 2| 3|2
--|--|--|--|--|--
  | 1| 4| 2| 2|

Now the same logic can be applied to the vertical 3-2 case in the fourth column, 3 -> * * 4 3 <- 2. Since the empty boxes faces the 3 and the only available numbers are 1 and 2, and since the 4 is in the 3rd position, they must be put in ascending order, 3 -> 1, 2, 4, 3 <- 2.

BRUTE FORCE APPROACH
Another possible solution is trying all combinations and checking if they're compatible with other numbers in the same column or row.
  | 3| 1| 2| 3|
--|--|--|--|--|--
 2|  | 4|  |  |3
--|--|--|--|--|--
 3|  | 3| 4|  |2 
--|--|--|--|--|--
 2|  | 2|  | 4|1
--|--|--|--|--|--
 1| 4| 1|  |  |2
--|--|--|--|--|--
  | 1| 4| 2| 2|

In the case above, taking as an example the very first row (2-3), all combinations of missing numbers can be tried. E.g. 1 - 4 - 2 - 3, 2 - 4 - 1 - 3, and 3 - 4 - 2 - 3 are all acceptable solutions. In order for this system to work, more combinations must be checked against each other. 
Maybe a recursive solution can be found for this issue.
Whatever way, this entails taking into account all possible combinations, which is quite a lot even in a 4x4 grid.
*/

