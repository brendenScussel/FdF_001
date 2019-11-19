/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:19:20 by bscussel          #+#    #+#             */
/*   Updated: 2019/09/06 18:19:59 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ABSOL(X) (((X) < 0) ? (-(X)) : (X))
# define DRIVE(x) ((x > 0) ? 1 : ((x < 0) ? -1 : 0))
# define WIN_W1 1600
# define WIN_H1 900
# define WIN_W2 1200
# define WIN_H2 720
# define CLR_R 0xDE0046
# define CLR_O 0xDE4600
# define CLR_Y 0xDEDE00
# define CLR_G 0x00DE46
# define CLR_B 0x0046DE
# define CLR_P 0x4600DE
# define CLR_C 0x00DEDE
# define CLR_M 0xDE00DE
# define CLR_K1 0x121212
# define CLR_K2 0x010101
# define CLR_W1 0xF0F0F0
# define CLR_W2 0xFFFFFF
# define KEY_A 0
# define KEY_D 2
# define KEY_E 14
# define KEY_H 4
# define KEY_Q 12
# define KEY_S 1
# define KEY_W 13
# define KEY_COM 43
# define KEY_DOT 47
# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define NUM_0 82
# define NUM_1 83
# define NUM_2 84
# define NUM_3 85
# define NUM_4 86
# define NUM_5 87
# define NUM_6 88
# define KEY_PLUS 24
# define KEY_MINS 27
# define NUM_PLUS 69
# define NUM_MINS 78
# define KEY_LFT 123
# define KEY_RGH 124
# define KEY_DWN 125
# define KEY_UP 126
# define KEY_ESC 53
# define ERR_USAGE 		"usage: ./fdf inputFile.fdf"
# define ERR_FILE		"ERROR incorrect file extention"
# define ERR_MLX_INIT	"ERROR mlx pointer initialization fail"
# define ERR_CAM_INIT	"ERROR camera initialization fail"
# define ERR_OPEN		"ERROR inputFile could not be accessed"
# define ERR_MAP_READ	"ERROR inputFile could not be read"
# define ERR_LST_ARR	"ERROR list to arry conversion"
# define ERR_MAP_SIZE	"ERROR map lines are not equal size"
# define CONTROL1		"Pan :"
# define CONTROL2		"[ARROW]/[W][A][S][D]"
# define CONTROL3		"Zoom:"
# define CONTROL4		"    [-][+]"
# define CONTROL5		"RotX:"
# define CONTROL6		"    [1][4]"
# define CONTROL7		"RotY:"
# define CONTROL8		"    [2][5]"
# define CONTROL9		"RotZ:"
# define CONTROL10		"    [3][6]"
# define CONTROL11		"Proj:"
# define CONTROL12		"    [Q][E]"
# define CONTROL13		"[ESC] to quit"

#endif
