//
//  UMTCAP_continue.h
//  ulibtcap
//
//  Created by Andreas Fink on 22/04/16.
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.

#import <ulib/ulib.h>
#import <ulibgt/ulibgt.h>
#import <ulibasn1/ulibasn1.h>
#import <ulibsccp/ulibsccp.h>
#import "UMTCAP_Variant.h"
#import "UMTCAP_UserProtocol.h"
#import "UMTCAP_asn1_objectIdentifier.h"

@class UMLayerTCAP;
@class UMTCAP_generic_asn1_componentPDU;
@class UMTCAP_asn1_dialoguePortion;

@interface UMTCAP_continue : UMLayerTask
{
    UMLayerTCAP *tcap;
    NSString *transactionId;
    UMTCAP_UserDialogIdentifier *userDialogId;
    UMTCAP_Variant variant;
    id<UMLayerUserProtocol> user;
    UMTCAP_asn1_dialoguePortion *dialoguePortion;
    SccpAddress *callingAddress;
    SccpAddress *calledAddress;
    TCAP_NSARRAY_OF_COMPONENT_PDU *components;
    NSDictionary *options;
}


- (UMTCAP_continue *)initForTcap:(UMLayerTCAP *)xtcap
                   transactionId:(NSString *)transactionId
                    userDialogId:(UMTCAP_UserDialogIdentifier *)userDialogId
                         variant:(UMTCAP_Variant)variant
                            user:(id<UMLayerUserProtocol>)xuser
                  callingAddress:(SccpAddress *)xsrc
                   calledAddress:(SccpAddress *)xdst
                 dialoguePortion:(UMTCAP_asn1_dialoguePortion *)xdialoguePortion
                      components:(TCAP_NSARRAY_OF_COMPONENT_PDU *)xcomponents
                         options:(NSDictionary *)xoptions;

@end
