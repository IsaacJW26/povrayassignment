//mantis bot

//mantis eye
#declare eye=
union
{
sphere
{
    <0,1,0> 1
    pigment { Red filter 0.5 }
    finish { emission 0.2 diffuse 0.1 phong 0.8 reflection 0.3}
    interior { ior 1.5 }
    
}
sphere
{
    <0,1,0> 0.8
    pigment { Red filter 0.1 }
    finish { emission 0.9 diffuse 0.1 phong 0.2 reflection 0.1}
    interior { ior 1.5 }
    
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
               pigment {Gray}
               finish { emission 0.2 diffuse 0.5 }
                rotate <0, 45, 0>
                translate <0,0,0> 
            }
            box
            {
                <3,4,3>,
                <-3,-2,-3>
                pigment {Gray}
                finish { emission 0.2 diffuse 0.5 }
                translate <0,0,-3>
            }
    }

    object {eye translate <-2,0,1>}

    object {eye translate <2,0,1>}
    //neck
    box
    {
        <0.5,0,0.5>,
       <-0.5,-3,-0.5>
       pigment {Gray}
       finish { ambient 0.2 diffuse 0.5 }
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
        <1,2,1>,
        <-1,-1,-1>
        pigment {Gray}
        finish { emission 0.1 diffuse 0.7 }
        translate <0,0.5,0>
        rotate <10,0,0>
    }
    
    box
    {
        <1,2,1>,
        <-1,-1,-1>
        pigment {Gray}
        finish { emission 0.1 diffuse 0.7 }
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
        <-0.5,-1,-0.5>
        pigment {Gray}
        finish { emission 0.1 diffuse 0.7 }
        translate <0,0.5,0>
        rotate <-10,0,0>
    }
    
    box
    {
        <0.5,2,0.5>,
        <-0.5,-3,-0.5>
        pigment {Gray}
        finish { emission 0.1 diffuse 0.7 }
        translate <0,-3,0>
            rotate <10,0,0>
    }
    
    scale<1,1,1>
    rotate <-20, -20, 0>
    translate <-2,0,2>
}

#declare rightleg=
object {
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
                finish { emission 1 diffuse 0 reflection 0.7}    
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
        pigment {Gray}
        finish { emission 0.1 diffuse 0.7 }    
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
        pigment {Gray}
        finish { emission 0.1 diffuse 0.7 }
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
        pigment {Gray}
        finish { emission 0.1 diffuse 0.7 }
        scale<0.7,1,0.7>
        translate <0,0.5,0>
        rotate <-10,0,0>
    }
    object {
    forearm
    translate <0,2.5,0>
    rotate <160,0,0>
    translate<0,-2.5,1>}

    scale<1,1,1>
    rotate <-20, 20, 0>
    translate <2,6,2>
}

