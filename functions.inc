#macro sinNormal(X)
 0.5+(sin(X*pi*2)*0.5)
#end

#macro accelDeccel(X)
X*X*X*(10+X*(6*X-15))
#end