
//roboteye
#declare roboteye=
difference
{
    box
    {
        <0.5,0.5,0.5>
        <-0.5,-.5,-0.5>

    }
    box
    {
        <0.4,0.2,0.2>
        <-0.4,-.2,-0.2>
        texture
        {
            pigment {Cyan}
            finish {emission 0.2+0.2*sin(clock*pi*16)}
        }
        translate <0,0,0.5>
    }
}
    

//robothead
#declare robothead=
union
{

    //righteye
    object
    {
        roboteye
        translate<1,0.2,1>
    }
    //lefteye
    object
    {
        roboteye
        translate<-1,0.2,1>
    }
    
    difference
    {
        union
        {
        //head
            box
            {
                <1,1,1>
                <-1,-3,-1>
            }
            //lips
            box
            {
                <1,1,1>
                <-1,-1,-1>
                
                scale<1,0.7,0.5>
                translate<0,-2,1>
            }
        }
        //inside mouth
        box
        {
            <1,1,1>
            <-1,-1,-1>
            
            scale<0.6,0.2,1>
            translate<0,-2,1.8>
            texture
            {
                pigment {Cyan}
                finish {emission 0.2+0.2*sin(clock*pi*16)}
            }
        }
    }
    
    
    texture
    {
        Aluminum
        //normal {bumps 0.5 scale 0.001}
        finish
        {
            emission 0.05
            brilliance 2.5
            diffuse 0.8
            reflection { 0.05 }
        }
    }
}


#declare slicevalue = 0;
#declare movevalue =0;
#declare transitionStart = 0.15;
#if(clock < transitionStart)
    #declare slicevalue = clock*2;
#else
    #declare slicevalue = 1;
    #declare movevalue =(clock - transitionStart)/(1-transitionStart);
#end

#declare slicedrobot=
union
{
    //tophalf
    difference
    {
        object {robothead}
        box
        {
                <1,1,1>
                <-1,0,-1>
    
                texture
                {
                    pigment {Orange*0.95+White*0.05}
                    finish
                    {
                        diffuse 0.1
                        //emission (2 * sinNormal((clock*2.2)-8))
                        emission 1.5*(1-clock)
                        specular 0.5
                    }
                }
                
                scale<slicevalue*10,10,10>
    
                rotate <10,0,225>
                translate<-2,-2.9,0>
        }
        
        translate<0,10+accelDeccel(movevalue)*4,0>
        rotate<-10,-accelDeccel(movevalue)*20,accelDeccel(movevalue)*5>
    }
    
    //bottom half
    difference
    {
        object {robothead}
        box
        {
                <1,0,1>
                <-1,-1,-1>
    
                texture
                {
                    pigment {Orange*0.95+White*0.05}
                    normal { pigment_pattern {cells scale 0.3}}
                    finish {
                    diffuse 0.1
                    //emission (2 * sinNormal((clock*1.6)+5))
                    emission 1.5*(1-clock)
                    specular 0.5
                    }
                }
                
                scale<slicevalue*10,10,10>
    
                rotate <10,0,225>
                translate<-2,-3.1,0>
        }
        
        translate<0,10-accelDeccel(movevalue)*8,0>
        rotate<-10,accelDeccel(movevalue)*20,-accelDeccel(movevalue)*5>
    }
}
