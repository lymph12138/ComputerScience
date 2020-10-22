question 1
clc;
clear;
n = 16;
h = 1/n;
x = 0:h:1;
b = (4*x.^3+5*x.^2-2*x+5)./(8*(x+1).^2);
A = zeros(n+1, n+1);
A(:, 1) = 1-x';
A(:, n+1) = 1/2-x';
for i = 1:n
    A(:, i+1) =  2*(1/(1+i*h)-x');
end
answer = (eye(n+1)-h/2*A)\(b');
scatter(x, answer, 'b');
hold on
xx = 0:0.01:1;
pp = spline(x, answer, xx);
plot(xx, pp, 'g');
hold on
plot(xx, 1./(1+xx).^2, 'r');
yy = 1./(1+xx).^2;
error = norm(pp-yy);

question 2


