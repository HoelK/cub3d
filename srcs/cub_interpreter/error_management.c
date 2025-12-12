/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 01:42:16 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/12 01:44:59 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	invalid_error(size_t line, uint8_t error)
{
	ft_write_error(" Format: line ");
	ft_putnbr_fd(2, line);
	ft_write_error(": Invalid ");
	if (error == SYNTAX)
		ft_write_errorn("Syntax");
	else if (error == ID)
		ft_write_errorn("Identifier");
	else if (error == MAP)
		ft_write_errorn("Map");
}

void	duplicate_error(size_t line, uint8_t duplicate)
{
	ft_write_error(" Format: line ");
	ft_putnbr_fd(2, line);
	ft_write_error(": Duplicate ");
	if (duplicate == SOUTH)
		ft_write_errorn("Texture : SOUTH");
	else if (duplicate == NORTH)
		ft_write_errorn("Texture : NORTH");
	else if (duplicate == WEST)
		ft_write_errorn("Texture : WEST");
	else if (duplicate == EAST)
		ft_write_errorn("Texture : EAST");
	else if (duplicate == FLOOR)
		ft_write_errorn("Color : floor");
	else if (duplicate == CEIL)
		ft_write_errorn("Color : ceiling");
}

void	missing_error(uint8_t missing)
{
	ft_write_error(": Missing ");
	if (missing == NORTH)
		ft_write_errorn("Texture : NORTH");
	else if (missing == SOUTH)
		ft_write_errorn("Texture : SOUTH");
	else if (missing == WEST)
		ft_write_errorn("Texture : WEST");
	else if (missing == EAST)
		ft_write_errorn("Texture : EAST");
	else if (missing == FLOOR)
		ft_write_errorn("Color : floor");
	else if (missing == CEIL)
		ft_write_errorn("Color : ceiling");
	else if (missing == MAP)
		ft_write_errorn("Element : Map");
}

void	parse_error(uint8_t mode, uint8_t error, size_t line)
{
	ft_write_error("ERROR: File");
	if (mode == INVALID)
		invalid_error(line, error);
	else if (mode == DUPLICATE)
		duplicate_error(line, error);
	else
		missing_error(error);
}

