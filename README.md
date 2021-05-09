Implementation
--------------
Since there is only one torch for the entire group, after a team of 2 people
cross the bridge, one person has to return with the torch and accompany the
next person across the bridge.

The fastest person in the group should be this person who will cross the bridge
with each person. This person will return after dropping each person, and then
pickup the next person. If there are n people in the team, there will be (n-2)
roundtrips across the bridge and one one-way trip.

The input is a list of lists with first entry in each component of the
second-level lists referring to the length of the bridge, and the subsequent
entries providing information on Hiker name and the corresponding speed.

Testing
-------
Input is read from the file input.yml by default.
To use a different input file, specify the filename as command line argument.

eg.

./hiker input.yml

./hiker input1.yml

1. One test case configures 2 persons in the first bridge, and 2 additional
persons joining in the second bridge. This computes the total time taken
for the first 2 (only one trip) and 4 people across the second bridge.

2. Test with 3 people joining the second bridge.

3. Test case in which a person who joins in the second bridge is the fastest.

4. Test case in which there are 3 bridges and no hikers join in second bridge.

5. Test case with 4 bridges.


