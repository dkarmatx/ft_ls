/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:46:35 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/22 21:40:55 by hgranule         ###   ########.fr       */
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
	t_2b	general_flags;
	t_2b	sort_flags;
	t_2b	addlf_flags;
	t_2b	custom_flags;
}						t_flags;


# define DRW_1COL = (t_2b)0b1000000000000000
# define DRW_MCOL = (t_2b)0b0100000000000000
# define DRW_LCOL = (t_2b)0b0010000000000000
# define DIR_ASFI = (t_2b)0b0001000000000000
# define RECUR_LS = (t_2b)0b0000100000000000

# define SORTI_R_ = (t_2b)0b1000000000000000
# define SORTI_T_ = (t_2b)0b0100000000000000
# define SORTI_U_ = (t_2b)0b0010000000000000
# define SORTI_F_ = (t_2b)0b0001000000000000
# define SORTI_SB = (t_2b)0b0000100000000000

# define ADDLF_I_ = (t_2b)0b1000000000000000
# define ADDLF_TB = (t_2b)0b0100000000000000
# define ADDLF_E_ = (t_2b)0b0010000000000000
# define ADDLF_AA = (t_2b)0b0001000000000000
# define ADDLF_G_ = (t_2b)0b0000100000000000
# define ADDLF_H_ = (t_2b)0b0000010000000000
# define ADDLF_N_ = (t_2b)0b0000001000000000

# define CUSTM_GB = (t_2b)0b1000000000000000
# define CUSTM_FB = (t_2b)0b0100000000000000
# define CUSTM_LB = (t_2b)0b0010000000000000
# define CUSTM_AB = (t_2b)0b0001000000000000
# define CUSTM_A_ = (t_2b)0b0000100000000000

#endif
