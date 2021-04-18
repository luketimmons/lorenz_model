# lorenz_model
Code produced as part of a computational physics where the focus of the project was to model and analyse the Lorenz model of fluid dynamics.

The Lorenz system is a system of ordinary differential equation originally studied by the atmospheric scientist, Edward Lorenz. At the time, Lorenz was studying the basic equations of fluid mechanics, or Navier-Stokes equations, which are a complicated set of differential equations that describe the various parameters, such as temperature, density, velocity, of the fluid as functions of position and time. Due to their complicated nature, they are difficult to solve analytically in cases of practical interest and as a result Lorenz sought to solve the Navier-Stokes equations using a computational approach. He investigated the Rayleigh-B´enard problem, in which the top and bottom of a fluid in a container are held at different temperatures. Due to the fact that Lorenz did his work more than 40 years ago, he had to consider a greatly simplified version of the Navier-Stokes equations when applied to the Rayleigh-B´enard problem. He was able to reduce the problem to only three equations, now known as the Lorenz model.


The use of the Euler method to derive the solution to the Lorenz model was initially considered. However, the Euler method may not be appropriate for the Lorenz model as the Euler method is only an approximation and therefore the error terms associated with the method are not zero. As a result, in oscillatory problems, such as the Lorenz model, the errors introduced by the Euler method generally tend to accumulate such that the results generated are subject to instability. As a result, the Euler method is in general not suitable for oscillatory problems. Instead the second-order Runge-Kutta method can be used such that the results generated are more stable. As such the Runge-Kutta method was used to derive the solution to the model.

The next problem is to plot the variation of the Lorenz variable z as a function of time for three different values of r, 25, 10, 5; with a time step of 0.0001 seconds and initial condition x = 1, y = z = 0. 

In order to plot the variation of the variable z over time, a for loop can be used to insert data into a set of arrays for the variables x, y, z and the time t for each value of r. Using gnuplot, the data from the z array could then be plotted against the data from the t array. However, the standard gnuplot C++ file does not have a function for plotting three functions on the same space so the standard file will have to be edited to contain a function that plots three functions on the same graph. 

Following on from that, the next step is to plot the trajectory of the Lorenz model onto the x-z plane for the value of r of 25 with a time step of 0.0001 seconds and initial condition x = 1, y = z = 0. 

To plot the trajectory of the Lorenz model on to the x-z plane, the existing data from the previous step can be inputted into gnuplot to plot the values for the z and x variable onto the x-z plane.

The final step for the minimum goals is to plot Phase-space plots for the Lorenz model with r = 25 for a time step of 0.0001. Two phase plots must be plotted, the first for z against y with points plotted only when x = 0 and the second for z against x only when y = 0. 

In order to plot the phase plot of z against y only when x = 0, the program must first determine the point at which x = 0. An if statement, nested within a for loop, that will check if the value of x stored in an array is equal to zero could be used. If it equal to zero, the corresponding values for y and z will be stored into separate arrays (e.g phase y, phase z). If not, then no values will be entered into the arrays. The for loop will then run through the same section of code until all the values for x have been checked. The data from the arrays will then be inputed into gnuplot so that the phase plot can be obtained. 

Similarly for the phase plot of z against x only when y = 0, the points at which y = 0 must first be determined using an if statement nested within a for loop. If the value of y is zero then the corresponding values for x and z will be inputted into separate arrays (e.g. phase x, phase z). The for loop will then check each value of y until all have been checked. The data from the loop can then be inputted into gnuplot so that the phase plot of z against x can be obtained. 

The first of the stretch goals is concerned with showing that the results generated from the final step of the minimum goals is not dependent on the initial conditions of the system. This goal could be achieved by simple comparison between different sets of initial conditions for the variables x, y and z. 

The second and final stretch goal is the determination of the Lyapunov exponent for a number of trajectories of the Lorenz model near its transition to chaos at r = 24.74. As well as this, observations of the exponents change from negative in the non-chaotic regime to positive in the chaotic regime must be made. The Lyapunov exponent is a quantity that characterizes the rate of separation of infinitesimally close trajectories. To achieve this goal the program will generate three trajectories for the Lorenz system, each infinitesimally separated from each other and calculate the separation between the trajectories for each value of x, y and z.
