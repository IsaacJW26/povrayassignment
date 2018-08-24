
#include "colors.inc"
#include "textures.inc"   
#include "mantis.inc"

/*
//environment
sky_sphere {pigment {rgb <0.859,0.910,0.831>}}

#local p_start		=	64/image_width;
#local p_end_tune	=	8/image_width;
#local p_end_final	=	4/image_width;

#local smooth_eb	=	0.50;
#local smooth_count	=	75;

#local final_eb		=	0.1875;
#local final_count	=	smooth_count * smooth_eb * smooth_eb / (final_eb * final_eb);

global_settings{

radiosity
{
    pretrace_start p_start        // Use p_end_final for the pretrace_end value
    pretrace_end   p_end_final    //

    count final_count            // as calculated above

    nearest_count 20             // set nearest_count to 20 for final trace

    error_bound final_eb         //  from what we determined before, defined above
                                 //   halfway between 0.25 and 0.5

    recursion_limit 3            // Recursion should be near what you want it to be
                                 //  If you aren't sure, start with 3 or 4

    minimum_reuse 0.005          // Use a lower minimum reuse
    }
}
*/
  
camera {
        perspective
        location <0,8,10>
        right    x*image_width/image_height
        angle 100
        look_at <0,4,0>
          focal_point <0,0,0> blur_samples 200 aperture 0.1
}
        
light_source {<100,120,130> White*0.7
fade_distance 100
fade_power 5}
light_source {<100,120,0> Blue*0.3
fade_distance 100
fade_power 5}


light_source {<12,0,10> Yellow*1
fade_distance 5
fade_power 1}                 

//floor
box
{
 <-100,-5,-100>,
<100,-6,100>
pigment {checker Gray, Red scale 2}
finish {
	reflection {.1}
	ambient 0.1
	diffuse 0.7 } 

}

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
//mantis bot
object { mantisHead }

//torso
object {torso}

//leg left

object {leftleg}

object {rightleg}

//left arm
object {leftarm}

//right arm
union
{
    box
    {
        <0.5,2,0.5>,
        <-0.5,-3,-0.5>
        pigment {Gray}
        finish { ambient 0.1 diffuse 0.7 }
        scale<0.7,1,0.7>
        translate <0,0.5,0>
        rotate <-10,0,0>
    }
    //forearm
    union
        {
        box
        {
            <0.5,2,0.5>,
            <-0.5,-3,-0.5>
            pigment {Gray}
            finish { ambient 0.1 diffuse 0.7 }    
            scale<0.7,1,0.7>
            rotate <10,0,0>
            translate <0,0,1>
        }
        
            
        box
        {
            <0.5,2,0.5>,
            <-0.5,-3,-0.5>
            pigment { Orchid }
            finish { ambient 0.6 diffuse 0.3 }    
            scale<0.2,1,0.5>
            rotate <0,0,0>
            translate <0,0,2>
        }
        translate <1,2.2,0>
        rotate <90,0,0>
        translate<0,-2.2,0>
    }
    scale<1,1,1>
    rotate <-20, 20, 0>
    translate <2,6,2>
}








