//
//  UMTCAP_itu_asn1_abort.h
//  ulibtcap
//
//  Created by Andreas Fink on 29.03.16.
//  Copyright (c) 2016 Andreas Fink
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.

#import <ulibasn1/ulibasn1.h>
#import "UMTCAP_asn1.h"
@class UMTCAP_itu_asn1_dtid;
@class UMTCAP_itu_asn1_dialoguePortion;
@class UMTCAP_itu_asn1_pAbortCause;

@interface UMTCAP_itu_asn1_abort : UMTCAP_asn1
{
    UMTCAP_itu_asn1_dtid            *dtid;
    UMTCAP_itu_asn1_pAbortCause     *pAbortCause;
    UMTCAP_itu_asn1_dialoguePortion *uAbortCause;
}

@property(readwrite,strong) UMTCAP_itu_asn1_dtid            *dtid;
@property(readwrite,strong) UMTCAP_itu_asn1_pAbortCause     *pAbortCause;
@property(readwrite,strong) UMTCAP_itu_asn1_dialoguePortion *uAbortCause;

@end
