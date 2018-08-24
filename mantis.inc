//mantis bot
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
               finish { ambient 0.2 diffuse 0.5 }
                rotate <0, 45, 0>
                translate <0,0,0> 
            }
            box
            {
                <3,4,3>,
                <-3,-2,-3>
                pigment {Gray}
                finish { ambient 0.2 diffuse 0.5 }
                translate <0,0,-3>
            }
    }

    sphere
    {
        <0,1,0> 1
        pigment { Red filter 0.7 }
        finish { ambient 0.1 diffuse 0.1 phong 0.4 reflection 0.1}
        interior { ior 1.5 }
        translate <-2,0,0.8>
    }

    sphere
    {
        <0,1,0> 1
        pigment { Red filter 0.7 }
        finish { ambient 0.1 diffuse 0.1 phong 0.4 reflection 0.1}
        interior { ior 1.5 }
        translate <2,0,0.8>
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
        finish { ambient 0.1 diffuse 0.7 }
        translate <0,0.5,0>
        rotate <10,0,0>
    }
    
    box
    {
        <1,2,1>,
        <-1,-1,-1>
        pigment {Gray}
        finish { ambient 0.1 diffuse 0.7 }
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
        finish { ambient 0.1 diffuse 0.7 }
        translate <0,0.5,0>
        rotate <-10,0,0>
    }
    
    box
    {
        <0.5,2,0.5>,
        <-0.5,-3,-0.5>
        pigment {Gray}
        finish { ambient 0.1 diffuse 0.7 }
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

#declare leftarm=
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
            pigment {Orchid }
            finish { ambient 0.6 diffuse 0.3 }    
            scale<0.2,1,0.5>
            rotate <0,0,0>
            translate <0,0,2>
        }
    }
    scale<1,1,1>
    rotate <-20, -20, 0>
    translate <-2,6,2>
}