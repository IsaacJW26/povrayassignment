#include "colors.inc"
#include "textures.inc"   
#include "mantis.inc"
#include "functions.inc"
#include "slicedrobot.inc"
#include "lamppost.inc"

//environment
sky_sphere {pigment {rgb <0.0,0.0035,0.0114>}}

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

    recursion_limit 4          // Recursion should be near what you want it to be
                                 //  If you aren't sure, start with 3 or 4

    minimum_reuse 0.005          // Use a lower minimum reuse
    
    normal on
    }
}

fog
{
    distance 150
    color rgb<0.0,0.0,0.0>
    fog_type 2
    fog_offset 25
    fog_alt 1
    turbulence 0.1
    turb_depth 0.2
}
fog
{
    distance 150
    color rgb<0.0,0.0035,0.0114>
    fog_type 2
    fog_offset 15
    fog_alt 4
    turbulence 0.2
    turb_depth 0.2
}
fog
{
    distance 150
    color rgb<0.01, 0.01, 0.01>
    fog_type 2
    fog_offset 10
    fog_alt 2
}

#declare movingcam=  
camera
{
        perspective
        location <1,2,7-6*movevalue>
        right    x*image_width/image_height
        angle 100
        look_at <0,2,3-6*movevalue>
        focal_point <0,2,4-5*movevalue> blur_samples 200 aperture 0.25
}

#declare staticcam=  
camera {
        perspective
        location <-0,1,5>
        right    x*image_width/image_height
        angle 100
        look_at <0,1,-1>
//          focal_point <0,0,0> blur_samples 200 aperture 0.3
}


//camera
camera {movingcam}

difference
{
    sphere
    {
       <0,0,0>, 10000
    }
    
    sphere
    {
       <0,0,0>, 10000-1
    }
    
    pigment {rgb <0.0,0.0035,0.0114>}
    finish
    {
        emission 1.0
        diffuse 0.0
    }
}


object {mantis
scale<0.5,0.5,0.5>
translate<0,-3,-1>}

object
{
    slicedrobot
    translate <1,-7,5.5>
}


object{road}