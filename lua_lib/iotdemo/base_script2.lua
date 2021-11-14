helper_obj=MyHelper.Helper()
light_state=helper_obj:CheckLampState(0)
if light_state == 0 then 
    helper_obj:SetLampState(0,1)
end

if light_state == 1 then 
    helper_obj:SetLampState(0,0)
end
