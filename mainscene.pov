#include "colors.inc"
#include "textures.inc"   
#include "mantis.inc"
#include "functions.inc"
#include "slicedrobot.inc"
#include "lamppost.inc"

//environment
sky_sphere {pigment {rgb <0.130,0.135,0.15>}}

#local p_start		=	64/image_width;
#local p_end_tune	=	8/image_width;
#local p_end_final	=	4/image_width;

#local smooth_eb	=	0.50;
#local smooth_count	=	75;

#local final_eb		=	0.1875;
#local final_count	=	smooth_count * smooth_eb * smooth_eb / (final_eb * final_eb);
/*
global_settings{
radiosity
{
    pretrace_start p_start        // Use p_end_final for the pretrace_end value
    pretrace_end   p_end_final    //

    count final_count            // as calculated above

    nearest_count 20             // set nearest_count to 20 for final trace

    error_bound final_eb         //  from what we determined before, defined above
                                 //   halfway between 0.25 and 0.5

    recursion_limit 3          // Recursion should be near what you want it to be
                                 //  If you aren't sure, start with 3 or 4

    minimum_reuse 0.005          // Use a lower minimum reuse
    }
}
*/
#declare movingcam=  
camera {
        perspective
        location <5*cos(clock*pi*2),9+0.5*sin(clock*pi*2),5*sin(clock*pi*2)>
        right    x*image_width/image_height
        angle 100
        look_at <0,5,0>
          focal_point <0,0,0> blur_samples 200 aperture 0.1
}

#declare staticcam=  
camera {
        perspective
        location <5,10,5>
        right    x*image_width/image_height
        angle 100
        look_at <0,8,0>
          focal_point <0,0,0> blur_samples 200 aperture 0.1
}

//camera
camera {staticcam}
       
light_source {<0,20,63> White*0.7
fade_distance 100
fade_power 2}
light_source {<0,100,50> Blue*0.3
fade_distance 100
fade_power 2}


//light_source {<12,0,10> Yellow*1
//fade_distance 5
//fade_power 1}                 

//floor
/*
box
{
 <-100,-5,-100>,
<100,-6,100>
pigment {checker Gray, Red scale 2}
finish {
	reflection {.1}
	emission 0.1
	diffuse 0.7 } 

}*/

//start

/*
box
{
 <2,2,2>,
 <1,1,1>
 pigment {Gray}
 finish { ambient 0.2 diffuse 0.5 }
translate <0,-1,0> }
*/
//mantis------------
/*
//head of the forbidden one
object { mantisHead }

//torso
object {torso}

//leg left of the forbidden one

object {leftleg}
//right left of the forbidden one
object {rightleg}
//left arm of the forbidden one
object {leftarm}
//right arm of the forbidden one
object {rightarm}

//end of mantis----------------------
*/

//object {slicedrobot}

//road

box
{
 <-100,-5,-100>,
<100,-6,100>
pigment {Gray*0.3}
finish {
	reflection {.2}
	emission 0.05
	diffuse 0.5
	specular 0.2
	subsurface {translucency White}
	}
	normal {bumps scale 0.3 turbulence 0.1 }
}

//lamppost
object{lamppost
translate<-10,0,-10>
}
object{slicedrobot}