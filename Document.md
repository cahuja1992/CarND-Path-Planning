Model Documentation

The model comprises of majorly four parts:

Analyze Sensor Fusion Data

Select the optimal lane

Calculate target speed and the lane

Find the jerk minimizing tracjectories and fit splines to the waypoints

Find the closest car in the front lane and estimate the velocity, similarily find the car in rear and front cars in left and right lanes. In order to aachieve this, the following information provided is being used. car_id, car_x, car_y, car_vx, car_vy, car_s and car_d

By grouping the coordinates of every car and then calculating the distance.
cost_to_straight():
If no traffic then cost = 0
If traffic and front car > 50 then cost = 0
If closest car in front and gradually the distance is getting decreased then it is higle likly to colide.
cost_to_left() and cost_to_right() 
