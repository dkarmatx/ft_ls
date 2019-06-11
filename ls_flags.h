/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:46:35 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/10 23:43:18 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

typedef unsigned char	t_1b;
typedef unsigned short	t_2b;
typedef unsigned int	t_4b;
typedef unsigned long	t_8b;

typedef struct			s_inputflags
{
	t_2b	sort_flags;
	t_2b	addlf_flags;
	t_2b	custom_flags;
	t_1b	general_flags;
	t_1b	view_flags;
}						t_flags;

# define DIR_ASFI (t_1b)0b10
# define RECUR_LS (t_1b)0b01

# define DRW_1COL (t_1b)0b100
# define DRW_MCOL (t_1b)0b010
# define DRW_LCOL (t_1b)0b001

# define SORTI_R_ (t_2b)0b10000
# define SORTI_T_ (t_2b)0b01000
# define SORTI_U_ (t_2b)0b00100
# define SORTI_F_ (t_2b)0b00010
# define SORTI_SB (t_2b)0b00001

# define ADDLF_E_ (t_2b)0b10000
# define ADDLF_AA (t_2b)0b01000
# define ADDLF_G_ (t_2b)0b00100
# define ADDLF_H_ (t_2b)0b00010
# define ADDLF_O_ (t_2b)0b00001

# define CUSTM_I_ (t_2b)0b1000000
# define CUSTM_S_ (t_2b)0b0100000
# define CUSTM_GB (t_2b)0b0010000
# define CUSTM_FB (t_2b)0b0001000
# define CUSTM_LB (t_2b)0b0000100
# define CUSTM_AB (t_2b)0b0000010
# define CUSTM_A_ (t_2b)0b0000001

#endif
