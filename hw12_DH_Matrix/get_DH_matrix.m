function DH_matrix = get_DH_matrix(alpha,a,d,theta) %#codegen
% 根据参数生成DH矩阵
    DH_matrix = [cosd(theta)               -sind(theta)               0               a            ;
                 sind(theta)*cosd(alpha)   cosd(theta)*cosd(alpha)    -sin(alpha)     -sin(alpha)*d;
                 sind(theta)*sind(alpha)   cosd(theta)*sind(alpha)    cos(alpha)      cos(alpha)*d ;
                 0                         0                          0               1            ;];
end
