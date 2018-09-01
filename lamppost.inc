#include "colors.inc"
#include "textures.inc"

#declare metaltex=
texture
{
    pigment { rgb <0.658824, 0.658824, 0.658824> }
    finish {
        emission 0.1
        diffuse 0.7
        reflection 0.05
        brilliance 8
        specular 0.3
        roughness 0.3
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
            metaltex
            
        }
        scale <0.5,10,0.5>
        translate<0,5,0>
    }

    union
    {
    
        box
        {
            <1,1,1>
            <-1,-1,-1>
            texture
            {
                metaltex
                
            }
            scale <0.5,3,0.5>
            rotate<0,0,90>
            translate<0,0,0>
        }
        
        light_source
        {
            <0,-1,0>,Blue *0.5+White*0.5
            fade_distance 30
            fade_power 2
            looks_like 
            {
            
                difference
                {
        
                    sphere
                    {
                        <0,0,0>,1
                    }
                    
                    box
                    {
                        <1,2,1>
                        <-1,0,-1>
                    }
                    
                    texture
                    {
                        pigment {Blue *0.5+White*0.5}
                        finish
                        {
                            emission 0.8
                        }
                        
                    }

                }
            }
            scale <1,1,1>
            rotate<0,0,0>
            translate<2.5,0.5,0>
        }
        
        translate <2.5,15,0>
    }     
} 

#declare Rnd_1 = seed (1153);

//building
#declare building=
box
{
    <-0.5,0,-0.5>,
    <0.5,1,0.5>
    texture
    {
        pigment {
            brick
        pigment {color rgb<0.5,0.5,0.5>}
        pigment {color rgb<0.8,0.25,0.1>}
        
        mortar 0.35
           } //---- end of pigment ------
        //pigment {Brown *0.01+White*0.1}
        finish
        {
            emission 0.1
            diffuse 0.9
        }
        normal { brick 1 }
    }
}


//road
//left footpath
#declare roadwidth=40+clock*5;
#declare road=
union
{
    //left footpath
    box
    {
        <roadwidth/2,-4.5,-1000>,
        <1000,-6,1000>
        pigment {Gray*0.08}
        finish
        {
        	reflection {.001}
        	emission 0.05
        	diffuse 0.8
        	specular 0.01
        	subsurface {translucency White *0.01}
    	}
    	normal {bumps 0.1 scale 0.1 turbulence 0.1 }
    }
    //road
    box
    {
     <-roadwidth/2,-5,-1000>,
    <roadwidth/2,-6,1000>
    pigment {Gray*0.01}
    finish {
    	reflection {.004}
    	emission 0.05
    	diffuse 0.8
    	specular 0.35
    	subsurface {translucency White *0.01}
    	}
    	normal {bumps 0.7 scale 0.1 turbulence 0.1 }
    }
    
    //right footpath
    box
    {
        <-roadwidth/2,-4.5,-1000>,
        <-1000,-6,1000>
        pigment {Gray*0.08}
        finish
        {
        	reflection {.001}
        	emission 0.05
        	diffuse 0.8
        	specular 0.01
        	subsurface {translucency White *0.01}
    	}
    	normal {bumps 0.1 scale 0.1 turbulence 0.1 }
    }
    
    //lamppost right
    #for(index, 0, 10,1)
        object
        {
            lamppost
            translate<-(roadwidth/2)-5,0.1,-50*index +2>
        }
    #end
    //lamppost left
    #for(index, 0, 10,1)
        object
        {
            lamppost
            rotate<0,180,0>
            translate<(roadwidth/2)+5,0.1,-50*index+2.1>
        }
    #end
    
    
    
    
    
    
    
    
    
    
    /*
    //right building foreground
    #for(index, 0, 10,1)
        object
        {
            building
            scale<rand(Rnd_1)*50,rand(Rnd_1)*70,rand(Rnd_1)*50>
            translate<-(roadwidth)-5,-5,-20*index+2>
        }
    #end
    //right building background
    #for(index, 0, 10,1)
        object
        {
            building
            scale<rand(Rnd_1)*50,rand(Rnd_1)*300,rand(Rnd_1)*50>
            translate<-(roadwidth*4)-5,-5,-20*index+2>
        }
    #end
    
        //left building foreground
    #for(index, 0, 50,1)
        object
        {
            building
            scale<rand(Rnd_1)*50,rand(Rnd_1)*70,rand(Rnd_1)*50>
            translate<(roadwidth)+5,-5,-20*index+2>
        }
    #end
    */
    
        //right building foreground
    #for(index, 0, 50,1)
        object
        {
            box
            {
                <-0.5-rand(Rnd_1)*25,0,-0.5-rand(Rnd_1)*25>,
                <0.5+rand(Rnd_1)*25,rand(Rnd_1)*70,0.5+rand(Rnd_1)*25>
                texture
                {
                    pigment {
                        brick
                    pigment {Gray}
                    pigment {Gray*0.1*rand(Rnd_1)}
                    
                    mortar 0.1
                       } //---- end of pigment ------
                    //pigment {Brown *0.01+White*0.1}
                    finish
                    {
                        emission 0.1
                        diffuse 0.9
                    }
                    normal { brick 1 }
                }
            }
            //scale<rand(Rnd_1)*50,rand(Rnd_1)*70,rand(Rnd_1)*50>
            translate<-(roadwidth)-5,-5,-20*index+2>
        }
    #end
    //right building background
    #for(index, 0, 50,1)
        object
        {
            box
            {
                <-0.5-rand(Rnd_1)*25,0,-0.5-rand(Rnd_1)*25>,
                <0.5+rand(Rnd_1)*25,rand(Rnd_1)*350,0.5+rand(Rnd_1)*25>
                texture
                {
                    pigment {
                        brick
                    pigment {Gray}
                    pigment {Gray*0.1*rand(Rnd_1)}
                    
                    mortar 0.1
                       } //---- end of pigment ------
                    //pigment {Brown *0.01+White*0.1}
                    finish
                    {
                        emission 0.1
                        diffuse 0.9
                    }
                    normal { brick 1 }
                }
            }
            //scale<rand(Rnd_1)*50,rand(Rnd_1)*300,rand(Rnd_1)*50>
            translate<-(roadwidth*3)-5,-5,-20*index+2>
        }
    #end
    
        //left building foreground
    #for(index, 0, 50,1)
        object
        {
            box
            {
                <-0.5-rand(Rnd_1)*25,0,-0.5-rand(Rnd_1)*25>,
                <0.5+rand(Rnd_1)*25,rand(Rnd_1)*70,0.5+rand(Rnd_1)*25>
                texture
                {
                    pigment {
                        brick
                    pigment {Gray}
                    pigment {Gray*0.1*rand(Rnd_1)}
                    
                    mortar 0.1
                       } //---- end of pigment ------
                    //pigment {Brown *0.01+White*0.1}
                    finish
                    {
                        emission 0.1
                        diffuse 0.9
                    }
                    normal { brick 1 }
                }
            }
            //scale<rand(Rnd_1)*50,rand(Rnd_1)*70,rand(Rnd_1)*50>
            translate<(roadwidth)+5,-5,-20*index+2>
        }
    #end
    
    //left building background
    #for(index, 0, 50,1)
        object
        {
            box
            {
                <-0.5-rand(Rnd_1)*25,0,-0.5-rand(Rnd_1)*25>,
                <0.5+rand(Rnd_1)*25,rand(Rnd_1)*350,0.5+rand(Rnd_1)*25>
                texture
                {
                    pigment {
                        brick
                    pigment {Gray}
                    pigment {Gray*0.1*rand(Rnd_1)}
                    
                    mortar 0.1
                       } //---- end of pigment ------
                    //pigment {Brown *0.01+White*0.1}
                    finish
                    {
                        emission 0.1
                        diffuse 0.9
                    }
                    normal { brick 1 }
                }
            }
            //scale<rand(Rnd_1)*50,rand(Rnd_1)*300,rand(Rnd_1)*50>
            translate<(roadwidth*3)+5,-5,-20*index+2>
        }
    #end
    
}
