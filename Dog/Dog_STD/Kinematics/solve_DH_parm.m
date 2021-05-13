function [ang_alpha,a,d,ang_theta] = solve_DH_parm(DH_matrix)
    syms ang_alpha a d ang_theta
    DH_matrix_parm = get_DH_matrix(ang_alpha,a,d,ang_theta);
    e1 = DH_matrix_parm==DH_matrix;
    [ang_alpha,a,d,ang_theta] = vpasolve(e1(1),e1(2),e1(13),e1(14));
    ang_alpha = double(ang_alpha);
    a = double(a);
    d = double(d);
    ang_theta = double(ang_theta);
end