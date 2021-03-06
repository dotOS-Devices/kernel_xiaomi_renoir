/*
 * Copyright (c) 2019-2020 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: wlan_cfg80211_interop_issues_ap.h
 *
 * This Header file provide declaration for cfg80211 command handler API
 */

#ifndef __WLAN_CFG80211_INTEROP_ISSUES_AP_H__
#define __WLAN_CFG80211_INTEROP_ISSUES_AP_H__

#include <wlan_objmgr_cmn.h>
#include <qdf_types.h>
#include <net/cfg80211.h>
#include <qca_vendor.h>

#ifdef WLAN_FEATURE_INTEROP_ISSUES_AP

extern const struct nla_policy
	interop_issues_ap_policy
	[QCA_WLAN_VENDOR_ATTR_INTEROP_ISSUES_AP_MAX + 1];

#define FEATURE_INTEROP_ISSUES_AP_VENDOR_COMMANDS \
{ \
	.info.vendor_id = QCA_NL80211_VENDOR_ID, \
	.info.subcmd = QCA_NL80211_VENDOR_SUBCMD_INTEROP_ISSUES_AP, \
	.flags = WIPHY_VENDOR_CMD_NEED_WDEV | \
		 WIPHY_VENDOR_CMD_NEED_NETDEV | \
		 WIPHY_VENDOR_CMD_NEED_RUNNING, \
	.doit = wlan_cfg80211_set_interop_issues_ap_config, \
	vendor_command_policy(interop_issues_ap_policy, \
			      QCA_WLAN_VENDOR_ATTR_INTEROP_ISSUES_AP_MAX) \
},

#define FEATURE_INTEROP_ISSUES_AP_VENDOR_COMMANDS_INDEX \
	[QCA_NL80211_VENDOR_SUBCMD_INTEROP_ISSUES_AP_INDEX] = { \
		.vendor_id = QCA_NL80211_VENDOR_ID, \
		.subcmd = QCA_NL80211_VENDOR_SUBCMD_INTEROP_ISSUES_AP \
	},

/**
 * wlan_cfg80211_init_interop_issues_ap() - init interop issues ap setting
 * @pdev: the pointer of pdev object
 *
 * Return: none
 */
void wlan_cfg80211_init_interop_issues_ap(struct wlan_objmgr_pdev *pdev);

/**
 * wlan_cfg80211_set_interop_issues_ap_config() - set interop issues ap config
 * @wiphy: pointer to wireless wiphy structure
 * @wdev: pointer to wireless_dev structure
 * @data: Pointer to the data to be passed via vendor interface
 * @data_len: Length of the data to be passed
 *
 * Return: Return the Success or Failure code
 */
int wlan_cfg80211_set_interop_issues_ap_config(struct wiphy *wiphy,
					       struct wireless_dev *wdev,
					       const void *data, int data_len);
#else
static inline
void wlan_cfg80211_init_interop_issues_ap(struct wlan_objmgr_pdev *pdev) {}
#define FEATURE_INTEROP_ISSUES_AP_VENDOR_COMMANDS
#define FEATURE_INTEROP_ISSUES_AP_VENDOR_COMMANDS_INDEX
#endif
#endif /* __WLAN_CFG80211_INTEROP_ISSUES_AP_H__ */
