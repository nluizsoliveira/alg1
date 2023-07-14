function main()
    X = input('');
    Y = input('');

    for degree = 1:3
        rows = length(X);
        cols = degree + 1;
        zero_matrix = zeros(rows, cols);
        design_matrix = get_design_matrix(X, zero_matrix, degree);
        coefficients_array = get_coefficients_array(design_matrix, Y);
        approximations = design_matrix * coefficients_array;
        truncation_error = sum((Y' - approximations).^2);
        display_info(coefficients_array, approximations, truncation_error, degree);
    end
end

function design_matrix = get_design_matrix(X, initial_matrix, degree)
    temporary_matrix = initial_matrix;
    for power = 0:degree
        descending_power = degree - power;
        X_raised_to_power = X .^ descending_power;
        column_index = power + 1;
        temporary_matrix = fill_column(temporary_matrix, column_index, X_raised_to_power);
    end
    design_matrix = temporary_matrix;
end

function matrix = fill_column(matrix, column_index, data)
    matrix(:, column_index) = data;
end


function coefficients_array = get_coefficients_array(matrix, Y)
    coefficients_array = matrix \ Y';
end

function display_info(coefficients_array, approximations, truncation_error, degree)
    fprintf('Polinômio de grau %d\n', degree);
    fprintf('-> Coeficientes:');
    fprintf(' %.4f', coefficients_array);
    fprintf('\n-> Aproximações:');
    fprintf(' %.4f', approximations);
    fprintf('\n-> Erro de truncamento: %.4f\n\n', truncation_error);
end

main()