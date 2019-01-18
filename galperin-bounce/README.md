# Galperin Bounce - Calculating Pi through Elastic Collision

Place two boxes on the half line [0,\infty): the small box is at rest, the bigger box is to the right moving left towards the small box. At x=0 is an elastic wall. Assuming all collision is elastic, hence the kinetic energy is preserved. In addition to that, number of collisions happen depends on the ratio of the boxes' masses. 

Suppose the masses of the two are equal (ratio=1), we observe the following:
- Box 1, at rest initially, collides with Box 2 which is coming from the left
- Box 1 will move to the left and bounce off the wall, Box 2 will set to rest 
- Box 1 will move the the right after colliding with elastic wall, hit Box 2 which is at rest. Box 2 then moves to the right.

Hence, there are 3 collisions in total for ratio=1. The first (1) number of \pi is 3. Coincidence?

Let's find out with a simple C++ scripts. Happy Physics everyone!

