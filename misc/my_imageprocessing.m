%in this function, you should finish the image processing function to
%extract the longitude and latitude lines using any mothods you consider 
%appropriate.
%please output the image only contains the longitude and latitude lines 
%and the backgroud.
function output = my_imageprocessing(input_image)
    function [all,cov1, cov2] = comp_stat(window)
        all=0;
        xsum = zeros(size(window,1)*size(window,2),1);
        ysum = zeros(size(window,1)*size(window,2),1);
        for ii = 1:size(window,1)
            for jj = 1:size(window,2)
                if window(ii,jj) ~= 0
                    all = all + 1;
                    xsum(all) = ii;
                    ysum(all) = jj;
                end
            end
        end
        xsum = xsum(1:all);
        ysum = ysum(1:all);
        cov1 = cov(xsum);
        cov2 = cov(ysum);
    end

    function cnt = connstat(tmp)
        cnt = 0;
        for it = 1:size(tmp,1)
            if tmp(it,1) ~=0
                cnt = cnt + 1;
            end
            if tmp(it,size(tmp,2)) ~= 0
                cnt = cnt + 1;
            end
        end
        for jt = 1:size(tmp,2)
            if tmp(1,jt) ~= 0
                cnt = cnt + 1;
            end
            if tmp(size(tmp,1), jt) ~= 0
                cnt = cnt + 1;
            end
        end
    end
    
    tmp = input_image; 
    h = size(input_image, 1);
    w = size(input_image, 2);
    k = 17;
    for i = 1:h/k
        for j = 1:w/k
            window = input_image(i*k-(k-1):i*k, j*k-(k-1):j*k);
            [a,covx, covy] = comp_stat(window);
            if ~((a< k + 3)|| (a > 2 * k - 4 && a < 2 * k ))
                tmp(i*k-(k-1):i*k, j*k-(k-1):j*k) = 0;
            end
            if covx > 0.15 * (k*k-1) || covy > 0.15 * (k*k - 1)
                tmp(i*k-(k-1):i*k, j*k-(k-1):j*k) = 0;
            end
        end
    end
    s_list=[5,6,7,8,9];
    output = tmp;
    for s = s_list
        k = 2 * s + 1;
        for i = 1 : h/s
            xs = (i-1) * s + 1;
            xe = xs + k;
            if xe > h
                break;
            end
            for j = 1 : w/s
                ys = (j-1) * s + 1;
                ye =  ys + k;
                if ye > w
                    break;
                end
                window = tmp(xs:xe,ys:ye);
                if connstat(window) == 0
                    output(xs:xe, ys:ye) = 0;
                end
            end
        end
    end
end