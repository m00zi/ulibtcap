//
//  UMTCAP_itu_begin.m
//  ulibtcap
//
//  Created by Andreas Fink on 24.03.16.
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.

#import "UMTCAP_itu_begin.h"
#import "UMLayerTCAP.h"
#import "UMTCAP_itu_asn1_dialoguePortion.h"
#import "UMTCAP_itu_asn1_begin.h"
#import "UMTCAP_itu_asn1_otid.h"
#import "UMTCAP_itu_asn1_componentPortion.h"

@implementation UMTCAP_itu_begin


- (void)main
{
    if(tcap.logLevel <= UMLOG_DEBUG)
    {
        [tcap.logFeed debugText:[NSString stringWithFormat:@"UMTCAP_itu_begin for transaction %@",transactionId]];
    }

    UMTCAP_Transaction *t = [tcap findTransactionByLocalTransactionId:transactionId];
    UMTCAP_itu_asn1_begin *q = [[UMTCAP_itu_asn1_begin alloc]init];
    UMTCAP_itu_asn1_otid *otid = [[UMTCAP_itu_asn1_otid alloc]init];
    
    if(transactionId == NULL)
    {
        [tcap.logFeed majorErrorText:@"why is the transaction ID not yet set?!?"];
        transactionId = [tcap getNewTransactionId];
    }

    otid.transactionId = transactionId;

    q.otid = otid;
    q.dialoguePortion = (UMTCAP_itu_asn1_dialoguePortion *)dialoguePortion;
        
    if(components.count > 0)
    {
        UMTCAP_itu_asn1_componentPortion *componentsPortion = [[UMTCAP_itu_asn1_componentPortion alloc]init];
        for(id item in components)
        {
            [componentsPortion addComponent:(UMTCAP_itu_asn1_componentPDU *)item];
        }
        q.componentPortion = componentsPortion;
    }
    else
    {
        [tcap.logFeed majorErrorText:@"componentsCount is zero"];
    }
    [t touch];

    NSData *pdu = [q berEncoded];
    if(pdu == NULL)
    {
        [tcap.logFeed minorErrorText:@"BER encoding of PDU failed"];
    }
    else
    {
        if(tcap.logLevel <= UMLOG_DEBUG)
        {
            NSString *s = [NSString stringWithFormat:@"Sending PDU to %@: %@", tcap.attachedLayer.layerName, pdu];
            [tcap.logFeed debugText:s];
        }
        [tcap.attachedLayer sccpNUnidata:pdu
                            callingLayer:tcap
                                 calling:callingAddress
                                  called:calledAddress
                        qualityOfService:0
                                 options:options];
    }
}

@end
