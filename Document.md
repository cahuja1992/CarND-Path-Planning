Model Documentation

The model comprises of majorly four parts:

* Analyze Sensor Fusion Data
* Select the optimal lane
* Calculate target speed and the lane
* Find the jerk minimizing tracjectories and fit splines to the waypoints

In order to accomplish all the above mentioned tasks, following things has been accomodated int eh model:

1. Find the closest car in the front lane and estimate the velocity, similarily find the car in rear and front cars in left and right lanes. In order to aachieve this, the following information provided is being used. car_id, car_x, car_y, car_vx, car_vy, car_s and car_d
By grouping the coordinates of every car and then calculating the distance.

2. cost_to_straight():
   - If no traffic then cost = 0
   - If traffic and front car > 50 then cost = 0
   - If closest car in front and gradually the distance is getting decreased then it is highly likely to collide then cost = 500
  
  cost_to_left() 
   - If no left lane exists then cost = 500
   - If left lane exists and not (12 < closest car < 50) then cost = 150
   - If left lane exists and 12 < closest car < 50 it is dangerous to make the turn then cost = 500
   
  cost_to_right() 
   - If no right lane exists then cost = 500
   - If right lane exists and not (12 < closest car < 50) then cost = 150
   - If right lane exists and 12 < closest car < 50 it is dangerous to make the turn then cost = 500
   
  cost_to_brake()
   - cost = 200, because it is not most likely than changing the lane therefore it has to be more than lane changing 
   
