#declare lampstick=
union
{
    box
    {
        <1,1,1>
        <-1,-1,-1>
        texture
        {
            pigment {Gray}
            
        }
        scale <0.5,3,0.5>
        rotate<0,0,90>
        translate<2.5,15,0>
    }

    light_source
    {
        <0,0,0>,Yellow
        looks_like 
       {
            difference
            {
    
                sphere
                {
                    <0,-1,0>,1
                }
                
                box
                {
                    <1,1,1>
                    <-1,-1,-1>
                }
                
                texture
                {
                    pigment {Yellow *0.5+White*0.5}
                    
                }
                scale <1,1,1>
                rotate<0,0,0>
                translate<4.5,15.5,0>
            }
        }
    }
}   


#declare lamppost=
union
{
    box
    {
        <1,1,1>
        <-1,-1,-1>
        texture
        {
            pigment {Gray}
            
        }
        scale <0.5,10,0.5>
        translate<0,5,0>
    }

    object
    {
        lampstick
        rotate<0,0,-20>
    }
} 