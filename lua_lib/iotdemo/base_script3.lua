helper_obj=MyHelper.Helper()
light_state1=helper_obj:CheckLampState(0)
light_state2=helper_obj:CheckLampState(1)
light_state3=helper_obj:CheckLampState(2)
light_level1=helper_obj:GetDetectorValue(0)
light_level2=helper_obj:GetDetectorValue(1)

if (light_level1 == 0 and light_level2 ==0) then 
    helper_obj:SetLampState(0,1)
    helper_obj:SetLampState(1,1)
    helper_obj:SetLampState(2,1)
elseif(light_level1 > 90 and light_level2 > 90) then
    helper_obj:SetLampState(0,0)
    helper_obj:SetLampState(1,0)
    helper_obj:SetLampState(2,0)
elseif(light_level1 < 50 and light_level1 > 10 and light_level2 > 20) then
    helper_obj:SetLampState(0,1)
    helper_obj:SetLampState(1,0)
    helper_obj:SetLampState(2,0)
end

