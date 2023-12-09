/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:39:03 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/09 12:30:22 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

// -----ERRORS----------------
# define ARG_ERR_1		"A map is required. ❌\n\n\tUsage: ./fdf <map>\n\n"
# define ARG_ERR_2		"Only 1 map is required. ❌\n\n\tUsage: ./fdf <map>\n\n"
# define FORMAT_ERR		"A map in format *.fdf is required. ❌\n"
# define READ_ERR		"The map cannot be read. Check path. ❌\n"

// -----TERMINAL--------------
# define MAP_FILE_OK	"Map file ✅\n"
# define PARSING		"Parsing map...\n"
# define PARSING_OK		"Map parsing ✅\n"
# define LOADING_UI		"Loading User Interface...\n"
# define GOOD_BYE		"Goodbye 👋\n"

// -----WINDOW----------------
# define TITLE			"FDF - mguardia"
# define TITLE1			"/**********************\\"
# define TITLE2			"*    Fil de Fer (FDF)  *"
# define TITLE3			"\\**********************/"
# define MAP_INFO		"/* MODEL INFO */"
# define MAP_NAME		"Name: "
# define X_MAX			"X max: "
# define Y_MAX			"Y max: "
# define Z_MAX			"Z max: "
# define Z_MIN			"Z min: "
# define COLOR_THEMES	"/* COLOR THEMES */"
# define DEFAULT_THEME	"Nbr 1: "
# define INVERT_THEME	"Nbr 2: "
# define BETIS_THEME	"Nbr 3: "
# define PROYECTION		"/* PROYECTION */"
# define PROYECTION_1	"key P: "
# define PROYECTION_2	"key I: "
# define CONTROL_INFO	"/* OTHER CONTROLS */"
# define ZOOM			"Zoom: "
# define ZOOM_1			"-> scroll"
# define ZOOM_2			"-> + / -"
# define MOVE			"Move model: "
# define MOVE_1			"-> arrows"
# define MOVE_2			"-> click + drag"

#endif