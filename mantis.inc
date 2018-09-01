#include "functions.inc"
#include "math.inc"

#declare swingclock=0;
#if(clock < 0.2)
    #declare swingclock=0;
#else
    #if (clock < 0.45)
        #declare swingclock=(clock-0.2)/0.3;
    #else
        #declare swingclock=1;
    #end
#end


//mantis bot
#declare metaltexture=
texture
{
    //Chrome_Metal
    pigment {Gray *0.3 + Black *0.7}
    finish
    {
    emission 0
    diffuse 0.8
    specular 0.2
    }
    normal {cells 0.35 scale 0.5
    turbulence 0
    translate <0,sinNormal(clock)*5,0>}
}
//mantis eye
#declare eye=
light_source
{
    <0,1,0>,
    Red *0.5 + White *0.5
    fade_distance 5
    fade_power 2
    
    looks_like
    {
        union
        {
            sphere
            {
                <0,0,0> 1
                pigment { Red filter 0.5 }
                finish { emission 0.2 diffuse 0.1 phong 0.8 reflection 0.3
                transmit 1.0}
                texture {Glass}
                interior { ior 1.5 }
                
            }
            sphere
            {
                <0,0,0> 0.8
                pigment { Red filter 0.1 }
                finish { emission 0.9 diffuse 0.1 phong 0.2 reflection 0.1
                transmit 0.8}
                interior { ior 1.5 }
            }
        }
    }
}

//mantis head
#declare mantisHead=
merge
{
    difference
    {
    
            box
            {
                <2,1.5,2>,
                <-2,-0.5,-2>
                
                rotate <0, 45, 0>
                translate <0,0,0>
                texture {metaltexture} 
            }
            box
            {
                <3,4,3>,
                <-3,-2,-3>

                translate <0,0,-3>
                texture {metaltexture}
            }
            box
            {
                <3,1,3>,
                <-3,-1,-3>

                translate <0,3,0>
                rotate <45, 0, 0>
                texture {metaltexture}
            }
            texture {metaltexture}
    }

    object {eye translate <-2,0,1>}

    object {eye translate <2,0,1>}
    //neck
    box
    {
        <0.5,0,0.5>,
       <-0.5,-3,-0.5>
       texture {metaltexture}
        rotate <0, 0, 0>
        translate <0,0,1> 
    }

    rotate <20,0,0>
    translate <0,10,0>
}

#declare torso=
union
{
    box
    {
        <1.1,2.2,1>,
        <-1.1,-1.2,-1>
        texture {metaltexture}
        translate <0,0.5,0>
        rotate <10,0,0>
    }
    
    box
    {
        <1,2,1>,
        <-1,-1,-1>
        texture {metaltexture}
        translate <0,-3,0>
            rotate <-10,0,0>
    }
    translate <0, 5, 0>
}

#declare leftleg=
union
{
    box
    {
        <0.5,2,0.5>,
        <-0.5,-2,-0.5>
        texture {metaltexture}
        translate <0,0.5,0>
        rotate <-10,0,0>
    }
    
    box
    {
        <0.5,2,0.5>,
        <-0.5,-3,-0.5>
        texture {metaltexture}
        translate <0,-3,0>
            rotate <10,0,0>
    }
    
    scale<1,1,1>
    rotate <-20, -20, 0>
    translate <-2,0,2>
}

#declare rightleg=
object
{
    leftleg
    scale <-1,1,1>
}

//blade
#declare blade=
light_source
{
    <0,0,0>, Orchid * 0.2
    looks_like
    {
        difference
        {
            box
            {
                <0.5,2,0.5>,
                <-0.5,-3,-0.5>
                pigment { Orchid }
                finish { emission 0.7 diffuse 0 reflection 0.2}    
                scale<0.05,1,0.5>
                rotate <10,0,0>
                translate <0,0,1.6>
           
            }
        }
    }
}

#declare forearm=
//forearm
union
{
    box
    {
        <0.5,2,0.5>,
        <-0.5,-3,-0.5>
        texture {metaltexture}  
        scale<0.7,1,0.7>
        rotate <10,0,0>
        translate <0,0,1>
    }
    
    blade
}


#declare leftarm=
union
{
    box
    {
        <0.5,2,0.5>,
        <-0.5,-3,-0.5>
        texture {metaltexture}
        scale<0.7,1,0.7>
        translate <0,0.5,0>
        rotate <-10,0,0>
    }
    //forearm
    object {forearm}
    scale<1,1,1>
    rotate <-20, -20, 0>
    translate <-2,6,2>
}

#declare rightarm=
union
{
    box
    {
        <0.5,2,0.5>,
        <-0.5,-3,-0.5>
        texture {metaltexture}
        scale<0.7,1,0.7>
        translate <0,0.5,0>
        rotate <-10,0,0>
    }
    object {
        forearm
        translate <0,2.5,-1>
        rotate <90+85*swingclock,0,0>
        translate<0,-2.5,0.7>
    }

    scale<1,1,1>
    translate<0,-2.5,0>
    //resets to facing forward
    rotate<0,0,180>
    rotate<150,0,0>
    //animates arm
    
    rotate <-65-30*swingclock,0,0>

    rotate<0,90*swingclock,0>
    rotate <0, 0, 0>
    //rotate <0, 45, 0>
    translate <1.5,7.5,2>
}

#declare mantis=
union
{
    //mantis------------
    
    //head of the forbidden one
    object { mantisHead }
    
    //torso
    object {torso}
    
    //leg left of the forbidden one
    
    object {leftleg}
    //right left of the forbidden one
    object
    {
        rightleg
        rotate <0,0,0>
    }
    //left arm of the forbidden one
    object {leftarm}
    //right arm of the forbidden one
    object
    {
        rightarm
        rotate <0,0,0>
    }
    
    //end of mantis-
}