//include libraries in program
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <fstream>
using namespace std;
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "gnuplot.cxx"


//declare constants
const int max_number_steps = 5000000;

//declare array for time values
double value_t[max_number_steps];

//declare arrays for position values when r = r1
double value_x1[max_number_steps];
double value_y1[max_number_steps];
double value_z1[max_number_steps];

//declare arrays for position values when r = r2
double value_x2[max_number_steps];
double value_y2[max_number_steps];
double value_z2[max_number_steps];

//declare arrays for position values when r = r3
double value_x3[max_number_steps];
double value_y3[max_number_steps];
double value_z3[max_number_steps];

//declare arrays for positions in phase plot
double phase_x[max_number_steps];
double phase_y[max_number_steps];
double phase_z[max_number_steps];

//declare arrays for setting range of x and y axes in graphs
double xrange[2];
double yrange[2];

//main program
int main() {
	//declare variables
	double x_0, y_0, z_0, b, r1, r2, r3, dt, sigma, T , x_prime, y_prime, z_prime;
	int  nr, number_steps;


	
	//input values for initial conditions and set values r, b and sigma
	cout << "Enter an inital value for x: ";
	cin >> x_0;

	cout << "Enter an inital value for y: ";
	cin >> y_0;

	cout << "Enter an inital value for z: ";
	cin >> z_0;

	cout << "Enter a value for b: ";
	cin >> b;

	cout << "Enter first value for r: ";
	cin >> r1;
	
	cout << "Enter second value for r: ";
	cin >> r2;
	
	cout << "Enter third value for r: ";
	cin >> r3;

	cout << "Enter a value for sigma: ";
	cin >> sigma;

	cout << "Enter a value for the time step: ";
	cin >> dt;

	cout << "Enter a value for the total time: ";
	cin >> T;

	cin.get();
	
	//calculate number of steps
	number_steps = T/dt;
	
	//set initial values for each array
	value_t[0] = 0.0;
	value_x1[0] = x_0;
	value_y1[0] = y_0;
	value_z1[0] = z_0;
	value_x2[0] = x_0;
	value_y2[0] = y_0;
	value_z2[0] = z_0;
	value_x3[0] = x_0;
	value_y3[0] = y_0;
	value_z3[0] = z_0;

	//for loop to calculate x, y ,z and t values for each plot point when r = r1
	for (nr = 0; nr < number_steps-1; nr++)
	{
		x_prime = value_x1[nr] + ((sigma*dt)/2)*(value_y1[nr] - value_x1[nr]);
		y_prime = value_y1[nr] + (dt/2)*(r1*value_x1[nr] - value_x1[nr]*value_z1[nr] - value_y1[nr]);
		z_prime = value_z1[nr] + (dt/2)*(value_x1[nr]*value_y1[nr] - b*value_z1[nr]);
		
		value_t[nr + 1] = dt*(nr + 1);
		
		value_x1[nr + 1] = value_x1[nr] + dt*(sigma*(y_prime - x_prime));
		value_y1[nr + 1] = value_y1[nr] + dt*(r1*x_prime - y_prime - x_prime*z_prime);
		value_z1[nr + 1] = value_z1[nr] + dt*(x_prime*y_prime - b*z_prime);
	}
	
	//for loop to calculate x, y ,z and t values for each plot point when r = r2
	for (nr = 0; nr < number_steps-1; nr++)
	{
		x_prime = value_x2[nr] + ((sigma*dt)/2)*(value_y2[nr] - value_x2[nr]);
		y_prime = value_y2[nr] + (dt/2)*(r2*value_x2[nr] - value_x2[nr]*value_z2[nr] - value_y2[nr]);
		z_prime = value_z2[nr] + (dt/2)*(value_x2[nr]*value_y2[nr] - b*value_z2[nr]);
		
		value_x2[nr + 1] = value_x2[nr] + dt*(sigma*(y_prime - x_prime));
		value_y2[nr + 1] = value_y2[nr] + dt*(r2*x_prime - y_prime - x_prime*z_prime);
		value_z2[nr + 1] = value_z2[nr] + dt*(x_prime*y_prime - b*z_prime);
	}
	
	//for loop to calculate x, y ,z and t values for each plot point when r = r3
	for (nr = 0; nr < number_steps-1; nr++)
	{
		x_prime = value_x3[nr] + ((sigma*dt)/2)*(value_y3[nr] - value_x3[nr]);
		y_prime = value_y3[nr] + (dt/2)*(r3*value_x3[nr] - value_x3[nr]*value_z3[nr] - value_y3[nr]);
		z_prime = value_z3[nr] + (dt/2)*(value_x3[nr]*value_y3[nr] - b*value_z3[nr]);
		
		value_x3[nr + 1] = value_x3[nr] + dt*(sigma*(y_prime - x_prime));
		value_y3[nr + 1] = value_y3[nr] + dt*(r3*x_prime - y_prime - x_prime*z_prime);
		value_z3[nr + 1] = value_z3[nr] + dt*(x_prime*y_prime - b*z_prime);
	}
	
	//Print three functions on one graph using newly created gnuplot function.
	gnuplot_three_functions ("Z over time", "lines", "t", "z", value_t, value_z1, number_steps, "r=25", value_t, value_z2, number_steps, "r=10" , value_t, value_z3, number_steps, "r=5");
	
	//set values for range of x axis and range of y axis on graph
	xrange[0]=-20;
	yrange[0]=0;
	xrange[1]=20;
	yrange[1]=50;
	
	//Print one function on graph with set range for x and y axes using newly created gnuplot function
	gnuplot_one_function_range ("r=25", "lines", "X", "Z", value_x1, value_z1, number_steps, xrange, yrange);
	
	//set values for range of x axis and range of y axis on graph
	xrange[0]=-25;
	yrange[0]=0;
	xrange[1]=25;
	yrange[1]=45;
	
	//Print one function on graph with set range for x and y axes using newly created gnuplot function
	gnuplot_one_function_range ("r=25", "lines", "Y", "Z", value_y1, value_z1, number_steps, xrange, yrange);
	
	//set values for range of x axis and range of y axis on graph
	xrange[0]=-20;
	yrange[0]=-25;
	xrange[1]=20;
	yrange[1]=25;
	
	//Print one function on graph with set range for x and y axes using newly created gnuplot function
	gnuplot_one_function_range ("r=25", "lines", "X", "Y", value_x1, value_y1, number_steps, xrange, yrange);
	
	cout << "Phase-space plots of Lorenz model:" << endl ;
	cout << "Initial conditions are x_0 = 1, y_0 = z_0 = 0 and time step = 0.0001" << endl;
	
	
	//input new value for total time 
	cout << "Enter a value for the total time for phase plots (Recommended: 500): ";
	cin >> T;
	
	//calculate number of steps
	number_steps = T/dt;
	
	//set initial condition for x, y and z arrays
	value_x1[0] = 1;
	value_y1[0] = 0;
	value_z1[0] = 0;
	
	//for loop to calculate x, y and z for each plot point when r = r1
	for (nr = 0; nr < number_steps-1; nr++)
	{
		x_prime = value_x1[nr] + ((sigma*dt)/2)*(value_y1[nr] - value_x1[nr]);
		y_prime = value_y1[nr] + (dt/2)*(r1*value_x1[nr] - value_x1[nr]*value_z1[nr] - value_y1[nr]);
		z_prime = value_z1[nr] + (dt/2)*(value_x1[nr]*value_y1[nr] - b*value_z1[nr]);
		
		value_t[nr + 1] = dt*(nr + 1);
		
		value_x1[nr + 1] = value_x1[nr] + dt*(sigma*(y_prime - x_prime));
		value_y1[nr + 1] = value_y1[nr] + dt*(r1*x_prime - y_prime - x_prime*z_prime);
		value_z1[nr + 1] = value_z1[nr] + dt*(x_prime*y_prime - b*z_prime);
	}
	
	//declaration of variable for number of steps in phase plots 
	int phase_steps = number_steps-30*(1/dt);
	
	int i=0;
	
	//for loop that inputs values into phase arrays, if the value of x is between -0.0001 and 0.0001
	for (nr = 300000; nr < phase_steps-1; nr++)
	{
		if(value_x1[nr] < 0.0001 && value_x1[nr] > -0.0001){
			phase_y[i] = value_y1[nr];
			phase_z[i] = value_z1[nr];
			i=i+1;
		}
		
	}
	
	//set values for range of x axis and range of y axis on graph
	xrange[0]=-10;
	yrange[0]=0;
	xrange[1]=10;
	yrange[1]=30;
	
	//Print one function on graph with set range for x and y axes using newly created gnuplot function
	gnuplot_one_function_range ("r=25", "dots", "Y", "Z", phase_y, phase_z, phase_steps, xrange, yrange);
	
	//reset all values in phase arrays back to zero
	for (nr = 0; nr < phase_steps-1; nr++)
	{
			phase_x[nr] = 0.0;
			phase_z[nr] = 0.0;
			phase_y[nr] = 0.0;
	}
	
	i=0;
	
	//for loop that inputs values into phase arrays, if the value of y is between -0.0001 and 0.0001 for each plo
	for (nr = 300000; nr < phase_steps-1; nr++)
	{
		
		if(value_y1[nr] < 0.0001 && value_y1[nr] > -0.0001){
			phase_x[i] = value_x1[nr];
			phase_z[i] = value_z1[nr];
			i=i+1;
	  }
	}
	
	//set values for range of x axis and range of y axis on graph
	xrange[0]=-20;
	yrange[0]=0;
	xrange[1]=20;
	yrange[1]=40;

	//Print one function on graph with set range for x and y axes using newly created gnuplot function
	gnuplot_one_function_range ("r=25", "dots", "X", "Z", phase_x, phase_z, phase_steps, xrange, yrange);
	
	
	//reset all values in phase arrays back to zero
	for (nr = 0; nr < phase_steps-1; nr++)
	{
			phase_x[nr] = 0.0;
			phase_z[nr] = 0.0;
			phase_y[nr] = 0.0;
	}
	
	cout << "Phase-space plots of Lorenz model:" << endl ;
	cout << "Initial conditions are x_0 = 0, y_0 = z_0 = 1 and time step = 0.0001" << endl;
	
	//set initial values for x, y and z arrays
	value_x1[0] = 0;
	value_y1[0] = 1;
	value_z1[0] = 1;
	
	
	//for loop to calculate x, y and z for each plot point when r = r1
	for (nr = 0; nr < number_steps-1; nr++)
	{
		x_prime = value_x1[nr] + ((sigma*dt)/2)*(value_y1[nr] - value_x1[nr]);
		y_prime = value_y1[nr] + (dt/2)*(r1*value_x1[nr] - value_x1[nr]*value_z1[nr] - value_y1[nr]);
		z_prime = value_z1[nr] + (dt/2)*(value_x1[nr]*value_y1[nr] - b*value_z1[nr]);
		
		value_t[nr + 1] = dt*(nr + 1);
		
		value_x1[nr + 1] = value_x1[nr] + dt*(sigma*(y_prime - x_prime));
		value_y1[nr + 1] = value_y1[nr] + dt*(r1*x_prime - y_prime - x_prime*z_prime);
		value_z1[nr + 1] = value_z1[nr] + dt*(x_prime*y_prime - b*z_prime);
	}
	
	i=0;
	//for loop that inputs values into phase arrays, if the value of x is between -0.0001 and 0.0001
	for (nr = 300000; nr < phase_steps-1; nr++)
	{
		if(value_x1[nr] < 0.0001 && value_x1[nr] > -0.0001){
			phase_y[i] = value_y1[nr];
			phase_z[i] = value_z1[nr];
			i=i+1;
		}
		
	}
	
	//set values for range of x axis and range of y axis on graph
	xrange[0]=-10;
	yrange[0]=0;
	xrange[1]=10;
	yrange[1]=30;
	
	//Print one function on graph with set range for x and y axes using newly created gnuplot function
	gnuplot_one_function_range ("r=25", "dots", "Y", "Z", phase_y, phase_z, phase_steps, xrange, yrange);
	
	i=0;
	//for loop that inputs values into phase arrays, if the value of y is between -0.0001 and 0.0001
	for (nr = 300000; nr < phase_steps-1; nr++)
	{
		
		if(value_y1[nr] < 0.0001 && value_y1[nr] > -0.0001){
			phase_x[i] = value_x1[nr];
			phase_z[i] = value_z1[nr];
			i=i+1;
	  }
	}
	
	//set values for range of x axis and range of y axis on graph
	xrange[0]=-20;
	yrange[0]=0;
	xrange[1]=20;
	yrange[1]=40;

	//Print one function on graph with set range for x and y axes using newly created gnuplot function
	gnuplot_one_function_range ("r=25", "dots", "X", "Z", phase_x, phase_z, phase_steps, xrange, yrange);
	return 0;
}


