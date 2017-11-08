# Model Documentation

The model comprises of majorly four parts:

* ## Analyze Sensor Fusion Data
* ## Select the optimal lane
* ## Calculate target speed and the lane
* ## Find the jerk minimizing tracjectories and fit splines to the waypoints

In order to accomplish all the above mentioned tasks, following things has been accomodated int eh model:

1. #### Find the closest car in the front lane and estimate the velocity, similarily find the car in rear and front cars in left and right lanes. In order to aachieve this, the following information provided is being used. car_id, car_x, car_y, car_vx, car_vy, car_s and car_d
By grouping the coordinates of every car and then calculating the distance.

2. #### The cost to change lane, keep in the same lane and brake is calculated in the following waya and at every instance based on the minimum cost is choosed
      cost_to_straight():
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
      
3. #### Given in the dataset is the `car_d` value which is used to decide the target speed for the lane

   Lane 1 : car_d = 2
   Lane 2 : car_d = 6
   Lane 3 : car_d = 10
   
   `car_s` is used to control the speed as follow: 
   Max speed, s increment = 0.415.
   Brake in the current lane, s increment to be retarded based on the speed of the front car.
   
4. #### Tracjectory planning
   -  Minimize acceleration and Jerk when the car first starts
   pos_s += min(target_s, (delta_prev_s*(1.005)+0.002))
   
   - smooth acceleration and braking
   double s_smoothing_steps = 80;
   double delta_s = (target_s_inc – prev_s_inc)/s_smoothing_steps;

   - Smooth change of lanes
   double d_smoothing_steps = 80;
   double delta_d = (target_d - prev_d) / d_smoothing_steps;
   pos_d += min(delta_d, 0.02);
   target_s += min(delta_s, 0.01);
   
   Then spline is fit on x, y, dx and dy based on pos_s which estimates pos_x, pos_y
